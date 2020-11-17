### Modify Default Voices In Python.

import pyttsx3 # by pip install pyttsx3


engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
# print(voices[1].id)
engine.setProperty('voice', voices[1].id)

rate = engine.getProperty("rate")
engine.setProperty("rate",180)

volume = engine.getProperty("volume")
# print("volume is {0}".format(volume))

engine.setProperty("volume",0.8)

def speak(audio):
    engine.say(audio)
    engine.runAndWait()
