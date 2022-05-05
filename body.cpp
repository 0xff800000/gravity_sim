#include "body.hpp"

void DrawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_LINE_LOOP);
    for (int i=0; i < num_segments; i++)   {
        float angle = 2.0 * M_PI * (float)i / (float)num_segments;
        float x = r * cosf(angle);
        float y = r * sinf(angle);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}


void Body::set_moveable(bool mov) {
    this->moveable = mov;
}

void Body::set_radius(float r) {
    this->radius = r;
}

void Body::set_bodies(std::vector<Body> * b) {
    this->bodies = b;
}


void Body::compute_force() {
    vec3 new_force(0.0, 0.0, 0.0);

    for(auto& body: *(this->bodies)) {
        // Discard itself
        if(&body == this)
            continue;


        // Compute force
        vec3 dist = this->position - body.position;
        float dist_s = dist.norm();
        vec3 direction = dist / dist_s;
        if(dist_s == 0)
            continue;
        vec3 f = direction * -1.0;
        f *= (G_CONST * this->mass * body.mass);
        f /= dist_s;

        new_force += f;
    }
    this->force = new_force;
}

bool Body::check_collisions(vec3 new_pos) {
    for(auto& body: *(this->bodies)) {
        // Discard itself
        if(&body == this)
            continue;

        // Check collisions
        float min_dist = this->radius + body.radius;
        if(this->position.distance(body.position) <= min_dist) {
            return true;
        }
    }
    return false;
}


void Body::move(float delta_t) {
    if(this->moveable == false) return;
    // Update the velocity
    vec3 acceleration = this->force / this->mass;
    this->velocity += acceleration * delta_t;

    // Update position
    vec3 displacement = this->velocity * delta_t;
    //if(!this->check_collisions(this->position + displacement))
        this->position += displacement;
}

void Body::update_draw() {
    DrawCircle(position.x, position.y, radius, 10);
}
