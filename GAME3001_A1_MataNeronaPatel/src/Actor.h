#pragma once
#ifndef __ACTOR__
#define __ACTOR__

#include "DisplayObject.h"

class Actor final : public DisplayObject {
public:
	Actor();
	~Actor();

	// Inherited via GameObject
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

private:
	
};


#endif /* defined (__ACTOR__) */