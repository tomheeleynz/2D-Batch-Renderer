xcrun -sdk macosx metal -c $1$2.metal -o $1$2.air
xcrun -sdk macosx metallib $1$2.air -o $1$2.metallib
echo "Shader Created"
