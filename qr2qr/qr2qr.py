#!/usr/bin/env python3

import cv2
import qrcode
import sys

img_in = cv2.imread(sys.argv[1])

detector = cv2.QRCodeDetector()
data, bbox, straight_qrcode = detector.detectAndDecode(img_in)

img_out = qrcode.make(data)
img_out.save('out.png')
