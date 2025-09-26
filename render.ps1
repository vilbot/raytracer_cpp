# 0. 
# cmake -B build
# 
# only have to do this once
#
# 1. 
# cmake --build build
#
# 2. 
# build/Debug/raytracer.exe > filename.ppm
#
# 3. 
# magick filename.ppm > filename.jpg

param(
    [string]$filename = "output",
    [string]$config = "Debug"
)

# Build the project
cmake --build build --config $config

# Determine the correct executable path based on configuration
$executablePath = "build/$config/raytracer.exe"

# Check if the executable exists
if (Test-Path $executablePath) {
    Write-Host "Running raytracer from: $executablePath"
    & $executablePath | Out-File -FilePath "ppm/$filename.ppm" -Encoding ASCII
    magick "ppm/$filename.ppm" "jpg/$filename.jpg"
    Write-Host "Generated: ppm/$filename.ppm and jpg/$filename.jpg"
} else {
    Write-Host "Executable not found at: $executablePath"
    Write-Host "Available files in build directory:"
    Get-ChildItem -Path "build" -Recurse -Name "*.exe"
}
