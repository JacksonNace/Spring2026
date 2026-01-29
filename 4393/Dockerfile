FROM python:3.11

RUN apt-get update && apt-get install -y \
  libgl1 \
  libglib2.0-0 \
  libsm6 \
  libxext6 \
  libxrender-dev \
  && rm -rf /var/lib/apt/lists/*

RUN pip install --no-cache-dir \
  opencv-python \
  numpy \
  matplotlib \
  pandas \
  pillow \
  scipy

WORKDIR /app

CMD ["python", "main.py"]