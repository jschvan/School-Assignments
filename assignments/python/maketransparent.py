#Python script to remove white background from image and turn red pixels into blue pixels
from PIL import Image

#opens and converts png to RGBA format
#RGBA allows manipulation or each pixels red, gree, blue, and transparency ("alpha") values
pic = Image.open("transparent_before.png")
rgba_pic = pic.convert("RGBA")

#adds all pixels to list 
datas = rgba_pic.getdata()

#creates new list to add modified pixels to
newData = []

#loops through each value in each pixel
for item in datas:
    #if red, turn blue
    if item[0] > 230 and item[1] < 230 and item[2] < 230:
        newData.append((0, 0, 255, 255))
    #if white, turn transparent
    elif item[0] > 230 and item[1] > 230 and item[2] > 230:
        newData.append((0, 0, 0, 0)) 
    else:
        #otherwise keep the same values
        newData.append(item) 

#uses modified pixel values to form new PNG file
pic.putdata(newData) 
pic.save("transparent_after.png", "PNG")
