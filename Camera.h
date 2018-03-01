#pragma once
class Camera
{
private:
	Camera() {};
	 template<static int,static Camera>* 
		D_instance = new template<static int,static Camera>();

public:
	static Camera GetInstance(int in_key);
	
};

