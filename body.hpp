#ifndef BODY_HPP
#define BODY_HPP


#include <vector>
#include <GL/freeglut.h> 
#include "vec3.hpp"

const float G_CONST = 6.67e-11;

class Body {
    private:
        vec3 position;
        vec3 force;
        vec3 velocity;
        float mass;
        float radius = 10.0;
        std::vector<Body> * bodies;
        

    public:
        Body(vec3 pos, vec3 vel, float m) {
            position = pos;
            velocity = vel;
            mass = m;
        }

        void set_bodies(std::vector<Body>*);
        void compute_force();
        void move(float);
        void update_draw();
};
#endif // BODY_HPP
