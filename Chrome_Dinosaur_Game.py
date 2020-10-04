import pyautogui # pip install pyautogui
from PIL import Image, ImageGrab # pip install pillow
# from numpy import asarray
import time

def hit(key):
    pyautogui.keyDown(key)
    return

def isCollide(data):
    # Draw the rectangle for birds
    for i in range(725, 825):
        for j in range(280, 328):
            if data[i, j] > 140:
                hit("up")
                return

    for i in range(700, 805):
        for j in range(230, 275):
            if data[i, j] > 140 and data[i, j] < 160:
                hit("down")
                return
    return

if __name__ == "__main__":
    print("Hey.. Dinosour game about to start in 3 seconds")
    time.sleep(3)
    hit('up') 

    while True:
        image = ImageGrab.grab().convert('L')  
        data = image.load()
        isCollide(data)
           
    #### below code is used to test the code with game by building dummy image on screen   
        #      # Draw the rectangle for cactus
        # for i in range(700, 715):
        #     for j in range(230, 275):
        #         data[i, j] = 140
        #        # Draw the rectangle for birds
        # for i in range(710, 730):
        #     for j in range(280, 330):
        #         data[i, j] = 160
        # image.show()
        # break
      

