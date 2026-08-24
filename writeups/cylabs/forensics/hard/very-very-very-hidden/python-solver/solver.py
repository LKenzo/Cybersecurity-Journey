from PIL import Image
import sys

def main():
    img = Image.open(sys.argv[1])
    pixels = img.load()
    width, height = img.size

    secret = []

    for y in range(height):
        for x in range(width):
            r, g, b = pixels[x, y]
            byte = ((b & 0x0F) << 4) | (g & 0x0F)
            secret.append(byte)

    result = bytes(secret).split(b'\x00')[0]
    print(result.decode('ascii', errors='ignore'))

main()