#ifndef GEMINI_VECTOR3
#define GEMINI_VECTOR3

class Vector3
{
public:
	static float DotProduct(const Vector3& a, const Vector3& b);
	static Vector3 VectorProjection(const Vector3& a, const Vector3& b);

	Vector3();
	Vector3(float global);
	Vector3(float x, float y, float z);
	Vector3(const Vector3 &copy);

	Vector3   operator*  (float global);	
	Vector3   operator+  (const Vector3 & rhs);
	Vector3   operator-  (const Vector3 & rhs);
	Vector3   operator*  (const Vector3 & rhs);
	Vector3 & operator=  (const Vector3 & rhs);	
	Vector3 & operator+= (const Vector3 & rhs);
	bool      operator== (const Vector3 & rhs);
	bool      operator!= (const Vector3 & rhs);

	float x_;
	float y_;
	float z_;
};


#endif 