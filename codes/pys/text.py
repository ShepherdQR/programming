'''
@Author: Shepherd Qirong
@Date: 2020-03-24 11:35:01
@Github: https://github.com/ShepherdQR
@LastEditors: Shepherd Qirong
@LastEditTime: 2020-04-03 19:01:01
@Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
'''

import time
import math

"""
print("hi")
a = time.time()
#time.sleep(1)


i  = math.atan(1000/1875)/math.pi*180#28du
j  = math.atan(1000/1525)/math.pi*180#33du


b = time.time()
print (i, j, 22/7, 355/113)
print( (b-a)*1000,  '\n')

list = [1, 2 ,3]
for i in range(len(list)):
    print(i)

print("\n","====","\n")   
cameraMode =0
camList = ["Linear00SL", "Linear01TL", "Linear02TR", "Linear03SR" ]
modeList = [[3], [3, 0, 2, 1]]

for i in range(len(modeList[cameraMode])):
    camCurrent = camList[modeList[cameraMode][i]]
    print(camCurrent)
"""



# import   time, os
# import numpy as np


# pi = 3.141592654
# timeCur = time.strftime("%Y%m%d%H%M%S", time.localtime())
# time_4=int(timeCur[-4:])
# timeMoment = time.time() # global time to define preiods

# modlePath = "/home/jellyfish/datasets/bunny/reconstruction/bun_zipper1889.ply"

# projectPath = "/home/jellyfish/cpps/FinalPaperSourceCodes/AutoScanProject-20200324"

# def outLog(line = "\n", timePassed= -1, logName = projectPath+"/logs/"+timeCur+".log"):
#     ## usage outLog("hi", 1)// with time
#     logNameFront = logName.split('.')[0]
#     if not os.path.exists(logNameFront):
#         os.makedirs(logNameFront)
#     with open(logName, 'a') as f:
#         f.write(line+"\n")
#         if(timePassed != -1):
#             time2 = time.time()
#             global timeMoment
#             time1 = timeMoment
#             timePeriod = (time2 - time1) * 1000 #ms
#             timeMoment = time2
#             f.write("Process time range: [" +str(time1) +"] to [" +str(time2) +"], time Pariod is " + str(timePeriod) + " ms.\n")


# a = "hello"
# b = "world"
# c = a+b[-2:] +"ok"
# print(c[:3])


# childName = "Scan.1"
# parentName = "Scan03SR"
# bpy.ops.object.select_all(action='SELECT')
# bpy.ops.object.select_all(action='DESELECT')
# bpy.ops.object.select_pattern(pattern=childName)
# bpy.context.scene.objects.active=bpy.context.scene.objects[childName]
# bpy.ops.object.select_pattern(pattern=parentName)
# bpy.context.scene.objects.active=bpy.context.scene.objects[parentName]##in(2.8) is :bpy.context.view_layer.objects.active
# bpy.ops.object.parent_set(type='OBJECT', keep_transform=True)







# camCurrent = "Linear03SR"
# bpy.ops.object.select_all(action='SELECT')
# bpy.ops.object.select_all(action='DESELECT')
# bpy.ops.object.select_pattern(pattern=camCurrent )
# bpy.context.scene.objects.active=bpy.context.scene.objects[camCurrent]
# bpy.ops.blensor.scan(filepath= "/home/jellyfish/cpps/FinalPaperSourceCodes/AutoScanProject-20200324/scanFiles/20200403001605/Scan03SR" + "1.pcd"   )

# if __name__ == "__main__":

    # camCurrent = "Linear03SR"
    # scanCollectionCurrent = "Scan"+ camCurrent[-4:]

        
    # outLog(line = "Scan log...\n", timePassed= 1, logName = projectPath+"/scanFiles/"+timeCur+"/"+scanCollectionCurrent+ "/"+"aa.log")



l = 2125

j_half  = math.atan( (2000-390)/1525  /2    )/math.pi*180#27.8du
print (j_half)