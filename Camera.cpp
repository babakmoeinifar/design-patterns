#include "Camera.h"



Camera* Camera::D_instance = 0;

Camera Camera::GetInstance(int in_key){
		if (!D_instance.ContainsKey(in_key)) {
		D_instance.Add(in_key, new Camera());
	}
	return D_instance[in_key];
}