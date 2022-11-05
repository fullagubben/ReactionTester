
from multiprocessing.resource_sharer import stop
from tracemalloc import start
import serial
from pathlib import Path
import vlc
import time
import pyautogui
arduino = serial.Serial('COM4', 9600, timeout=.1)



idlesong = vlc.MediaPlayer("idle.mp3")
startsong = vlc.MediaPlayer("start.mp3")         
stopsong = vlc.MediaPlayer("stop.mp3")		
	
	




         
def playidle():		# starts IDLE song and rises volume on spotify
	startsong.pause()
	pyautogui.keyDown('ctrl')   # 2.0 solution to "the spotify issue"
	pyautogui.press('up', presses=4)
	pyautogui.keyUp('ctrl')   
	


def playstart():   # starts HEARTBEAT and lowers volume on spotify
	pyautogui.keyDown('ctrl')  
	pyautogui.press('down', presses=4)
	pyautogui.keyUp('ctrl')    

	startsong.play()
	
 
def playstop():  # starts MARIO drop sound
	stopsong.play()  
	time.sleep(2)
	stopsong.stop(  )
	

      

 
while True:   
	input = arduino.readline()[:-2]               
	data = input.decode('utf-8')    #this line gets me some weird errors
	print (data)
	if data == "ledstart":
		playstart()  
	if data == "ledstop":
		playstop()
	if data == "ledidle":
		playidle()          