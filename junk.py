# Python script to permanently delete junk .exe files by Athar Wani
import os
import datetime
f = open("_logs_.txt", "w")
_ext = ".exe"
_files = [file for file in os.listdir(".") if file.endswith(_ext)]
for file in range(len(_files)):
    print(_files[file])
_input = input("Do you want to delete all these files? (y/n): ")
if _input == 'y' or _input == 'Y':
    for file in _files:
        os.remove(file)
        print("Deleted: "+file)
        f.write("Deleted: "+file+" at ["+str(datetime.datetime.now())+"]\n")
print("Successfully deleted all junk files!\nSee logs for details.")
f.close()
