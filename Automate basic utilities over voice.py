import pyttsx3
import datetime
import speech_recognition as sr
import wikipedia
import os
import webbrowser
import random
import smtplib

engine=pyttsx3.init('sapi5')
voices= engine.getProperty('voices')
print(voices[0].id)
engine.setProperty('voice',voices[0].id)

def speak(audio):
    engine.say(audio)
    engine.runAndWait()

def wishMe():
    hour=int(datetime.datetime.now().hour)
    if(hour>=0 and hour<12):
        speak('good morning ')

    elif(hour>=12 and hour<16):
        speak('good afternoon ')
    
    else:
        speak('good evening ')
    
    speak('how may i help you')


def takecommand():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print('listning...')
        r.pause_threshold=1
        audio= r.listen(source)

    try:
        print('recognizing..')
        query=r.recognize_google(audio,language='en-in')
        print('user said:',query)
        speak('okay Sir')


    except Exception:
        print('say that again')
        speak('say that again')
        return 'none'
    return query
    
def sendEmail(to,content):
    server=smtplib.SMTP('smtp.gmail.com',587)
    server.ehlo()
    server.starttls()
    server.login('kapiljain0209@gmail.com','kapil255347')
    server.sendmail('kapiljain0209@gmail.com',to,content)
    server.close()

if __name__ == "__main__":
    wishMe()
    
    while True:
        query=takecommand().lower()
        
        if 'wikipedia' in query:
            speak('searching wiki')
            query=query.replace('wiki','')
            results=wikipedia.summary(query,sentences=2)
            speak('according to wiki')
            print(results)
            speak(results)
        
        elif 'exit' in query:
            speak('thanks for using')
            exit()

        elif 'open youtube' in query:
            webbrowser.open('youtube.com')
        
        elif 'open google' in query:
            webbrowser.open('google.com')
        
        elif 'play music' in query:
            musicDir= 'E:\\Music'
            songs=os.listdir(musicDir)
            length=len(songs)
            no=random.randint(1,length)

            os.startfile(os.path.join(musicDir,songs[no]))
        
        elif 'next' in query:
            musicDir= 'E:\\Music'
            songs=os.listdir(musicDir)
            length=len(songs)
            no=random.randint(1,length)

            os.startfile(os.path.join(musicDir,songs[no]))

           








