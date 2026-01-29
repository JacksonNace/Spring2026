import cv2
import numpy as np
import sys

print(f"Python version: {sys.version}")
print(f"OpenCV version: {cv2.__version__}")

# Create a test image
img = np.zeros((200, 200, 3), dtype="uint8")
cv2.putText(img, 'IT WORKS!', (20, 100), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)

# Save to the mounted folder
cv2.imwrite('success.png', img)
print("Saved success.png to your project folder!")