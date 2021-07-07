import numpy as np
import cv2
import pickle

face_cascade = cv2.CascadeClassifier('cascades/data/haarcascade_frontalface_alt2.xml')
# eye_cascade = cv2.CascadeClassifier('cascades/data/haarcascade_eye.xml')
# smile_cascade = cv2.CascadeClassifier('cascades/data/haarcascade_smile.xml')

recogniser = cv2.face.LBPHFaceRecognizer_create()
recogniser.read("trainer.yml")

labels = {}
with open("labels.pickle", 'rb') as f:
	old_labels = pickle.load(f)
	labels = {v:k for k,v in old_labels.items()}

cap = cv2.VideoCapture(0) 

while True:
	ret, frame = cap.read()
	# Reads data frame by frame
	gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
	faces = face_cascade.detectMultiScale(gray, scaleFactor = 1.5, minNeighbors = 5)
	for (x,y,w,h) in faces:
		# print(x,y,w,h)
		# ROI is the region of interest. In this case, it is my face
		roi_gray = gray[y:y+h, x:x+w] #Location of this frame is in the []. This denotes the ROI
		roi_color = frame[y:y+h, x:x+w]
		id_, conf = recogniser.predict(roi_gray) #Label and confidence
		if conf>=45 and conf<=85:
			print(id_)
			print(labels[id_])
			font = cv2.FONT_HERSHEY_SIMPLEX
			name = labels[id_]
			color = (255,255,255)
			stroke = 2
			cv2.putText(frame, name, (x,y), font, 1, color, stroke, cv2.LINE_AA)


		#Now save this image of my face
		img_item = "hari-face.png"
		cv2.imwrite(img_item,roi_gray) #Assignment of picture

		#For rectangle surrounding face
		color = (0,255,255) #In BGR(0-255) format not RGB
		stroke = 2 #Line thickness
		end_cord_x = x + w
		end_cord_y = y + h
		# This draws rectangle onto the color frame
		cv2.rectangle(frame, (x,y), (end_cord_x, end_cord_y), color, stroke)  #Starting and ending coordinates for the face.
		eyes = eye_cascade.detectMultiScale(roi_gray)
		for (ex,ey,ew,eh) in eyes:
			cv2.rectangle(roi_color,(ex,ey),(ex+ew, ey+eh),(0,255,0),2)

		smile = smile_cascade.detectMultiScale(roi_gray)
		for (sx,sy,sw,sh) in smile:
			cv2.rectangle(roi_color,(sx,sy),(sx+sw, sy+sh),(0,255,0),2)

	#Display the resulting frame
	cv2.imshow('frame', frame) 
	# cv2.imshow('gray', gray) 
	# Shows the photo.Note: Its not imgshow
	if cv2.waitKey(20) & 0xFF == ord('q'):
   	    sbreak
   	    # Closes the frame on pressing q