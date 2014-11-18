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

  private:
      const double PI = 3.14159265359;

  public:

    glm::vec4 position;   // position-vector

    // orthonormal system of directions:
    glm::vec4 viewDir;    // viewing direction
    glm::vec4 upDir;      // up-vector
    glm::vec4 rightDir;   // right-vector (cross product of viewing and up-direction)

    // mouse position when rotatino starts
    glm::vec2 mouseStartPosition;


    // initialize the system with values suitable for the underlying scene.
    cameraSystem() {
        position = glm::vec4(50, 80, -160, 0);
        viewDir = glm::normalize(-position);
        upDir = glm::vec4(0, 1, 0, 0);

        glm::vec3 cross = glm::cross(glm::vec3(viewDir), glm::vec3(upDir));
        rightDir = glm::normalize(glm::vec4(cross.x, cross.y, cross.z, 0));
    }

    glm::mat4 getView() {
        glm::vec3 eye = glm::vec3(position);
        glm::vec3 center = glm::vec3(position + viewDir);
        glm::vec3 up = glm::vec3(upDir);

        return glm::lookAt(eye, center, up);
    }

// move the system forward along the viewing direction
   void moveForward(float delta) {
       position += delta * viewDir;
   }

    void moveBackward(float delta) {
        moveForward(-delta);
   }

   void yaw(float angle) {
       viewDir = glm::normalize(glm::transpose(getView()) * glm::vec4(glm::tan(angle * PI / 180.0f), 0, -1, 0));
       glm::vec3 cross = glm::cross(glm::vec3(viewDir), glm::vec3(upDir));
       rightDir = glm::normalize(glm::vec4(cross.x, cross.y, cross.z, 0));
   }


   void pitch(float angle) {
       viewDir = glm::normalize(glm::transpose(getView()) * glm::vec4(0, -glm::tan(angle * PI / 180.0f), -1, 0));
       glm::vec3 cross = glm::cross(-glm::vec3(viewDir), glm::vec3(rightDir));
       upDir = glm::normalize(glm::vec4(cross.x, cross.y, cross.z, 0));
   }


   void roll(float angle) {

       upDir = glm::normalize(glm::transpose(getView()) * glm::vec4(glm::tan(angle * PI / 180.0f), 1, 0, 0));
       glm::vec3 cross = glm::cross(glm::vec3(viewDir), glm::vec3(upDir));
       rightDir = glm::normalize(glm::vec4(cross.x, cross.y, cross.z, 0));
   }

};

