//
// Created by pokor on 14/12/2020.
//

#ifndef INFLUENCEMAPDEMO_COMPONENT_H
#define INFLUENCEMAPDEMO_COMPONENT_H


class Component {
public:
    /**
    * Default Constructor.
    */
    Component();
    /**
    * Create a virtual function so the class is polymorphic.
    */
    virtual void Update(float timeDelta) {};
};


#endif //INFLUENCEMAPDEMO_COMPONENT_H
