from flask import Flask
app = Flask(__name__)

@app.route('/blast/<colour>', methods=['POST'])
def hello_world(colour):
    r=int(colour[0:2], 16)
    g=int(colour[2:4], 16)
    b=int(colour[4:6], 16)
    print(r,g,b)
    with open('/dev/pi-blaster', 'w') as f:
        f.write('16={}\n'.format(r/256.0))
        f.write('23={}\n'.format(b/256.0))
        f.write('25={}\n'.format(g/256.0))
    return ''


