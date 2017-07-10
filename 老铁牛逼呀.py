import os
def search(dir, text):
    for x in os.listdir(dir):
        if os.path.isfile(os.path.join(dir,x)):
            if text in os.path.splitext(x)[0]:
                print('%s, %s'% (dir, x))
        if os.path.isdir(os.path.join(dir,x)):
            search(os.path.join(dir, x),text)


search('Test','lssss')
