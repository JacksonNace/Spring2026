set -e
docker build -t cpp-runner .
go run runner.go "${1:-Project1}"