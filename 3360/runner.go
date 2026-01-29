package main
import (
	"fmt"
	"os"
	"os/exec"
)

func main() {
	if len(os.Args) < 2 {
		fmt.Println("Usage: go run runner.go <ProjectFolderName>")
		return
	}
	projectName := os.Args[1]
	// os.getwd gets working directory
	pwd, _ := os.Getwd()
	projectPath := fmt.Sprintf("%s/CPPScripts/%s", pwd, projectName)

	fmt.Printf("Running %s...\n", projectName)

	// This creates the full docker cmd
	cmd := exec.Command("docker", "run", "--rm", 
		"-v", projectPath+":/app", 
		"cpp-runner")

	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr

	err := cmd.Run()
	if err != nil {
		fmt.Printf("Error: %v\n", err)
	}
}