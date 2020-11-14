checkHeaders:
	g++ cpp/headers/zCore/zCore.h -Icpp --std=c++17 -Wall


main:
	g++ exampleExec/main.cpp -Icpp -Icpp/headers/zCore --std=c++17 -c -DZSPACE_DYNAMIC_LIBRARY -DZSPACE_CORE=""

objects:
	g++ -c cpp/source/zCore/base/*.cpp -Wfatal-errors --std=c++17 -DZSPACE_DYNAMIC_LIBRARY -Icpp -DZSPACE_CORE=""

base:
	g++ cpp/source/zCore/base/*.cpp -Wfatal-errors --std=c++17 -DZSPACE_DYNAMIC_LIBRARY -Icpp -DZSPACE_CORE=""

zapp: objects
	g++ *.o cpp/source/zApp/zApp.cpp -Icpp -DZSPACE_CUDA_CALLABLE="" --std=c++17 -lGL -o zApp




matrixdefines:
	g++ -dM -E -x c++  cpp/source/zCore/base/zMatrix.cpp -Wfatal-errors --std=c++17 -DZSPACE_DYNAMIC_LIBRARY -Icpp -Wall -Wextra -DZSPACE_CORE=""

matrixobjects:
	g++ -c cpp/source/zCore/base/zMatrix.cpp -Wfatal-errors --std=c++17 -DZSPACE_DYNAMIC_LIBRARY -Icpp -Wall -Wextra -DZSPACE_CORE=""



