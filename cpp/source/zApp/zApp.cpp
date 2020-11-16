#include <headers/zInterface/functionsets/zFnMesh.h>
using namespace zSpace;

int main() {
    zObjMesh objMesh_in;
    zFnMesh fnMesh_in;
    fnMesh_in = zFnMesh(objMesh_in);
    fnMesh_in.from("unitCube.obj", zOBJ);
    return 0;
}
