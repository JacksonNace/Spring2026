import cv2
import numpy as np

# black image, white square
img = np.zeros((512, 512, 3), np.uint8)
cv2.rectangle(img, (100, 100), (400, 400), (255, 255, 255), -1)
cv2.imwrite('test_output.png', img)
print("✅ OpenCV successfully created test_output.png!")