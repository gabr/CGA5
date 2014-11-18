// Arkadiusz Gabrys qe83mepi
// Agnieszka Zacher by57zeja

/// Implement the camera system entirely here, which means: don't do only the declaration here and
/// create another file camera.cpp for the implementation. You might have been told that it is
/// bad programming style to put everything in a .h file, but it's perfectly fine for such a small
/// class! Plus, I don't want to open two files to read your solutions of this class!

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>


class cameraSystem {

  public:

    glm::vec4 position;   // position-vector

    // orthonormal system of directions:
    glm::vec4 viewDir;    // viewing direction
    glm::vec4 upDir;      // up-vector
    glm::vec4 rightDir;   // right-vector (cross product of viewing and up-direction)


    // initialize the system with values suitable for the underlying scene.
    cameraSystem() {
        position = glm::vec4(50, 80, -160, 0);
        viewDir = -position;
        upDir = glm::vec4(0, 1, 0, 0);

        glm::vec3 cross = glm::cross(glm::vec3(viewDir), glm::vec3(upDir));
        rightDir = glm::vec4(cross.x, cross.y, cross.z, 0);
    }

// move the system forward along the viewing direction
   void moveForward(float delta) {
    // TODO
   }

 //
    void moveBackward(float delta) {
    // TODO
   }

   void yaw(float angle) {
      // TODO
      // dont forget to update the other Vectors!!
   }


   void pitch(float angle) {
    // TODO
    // dont forget to update the other Vectors!!
   }


   void roll(float angle) {
      // TODO
     // dont forget to update the other Vectors!!
   }

};

