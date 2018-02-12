from colorsys import hsv_to_rgb
from time import sleep

def main():
    while True:
        for i in range(365):
            with open('/dev/pi-blaster', 'w') as dev:
                r, g, b = hsv_to_rgb(i/365.0, 0.5, 0.2)
                print(r, g, b)
                dev.write('16={}\n23={}\n25={}\n'.format(r, g, b))
                sleep(0.1)


if '__main__' == __name__:
    main()
