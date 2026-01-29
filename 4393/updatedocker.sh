set -e
docker build -t opencv-runner .
go run runner.go "${1:-Project1}"