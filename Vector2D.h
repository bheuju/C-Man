/* ==================== Vector2D ===================== 
 This class is to make use of vector coordinate system
 for our objects. (move, position)
 -------------------------------------------------------- 
  
======================================================== */

#pragma once
class Vector2D
{
public:
	Vector2D(){}

	Vector2D(float x, float y)
	{
		mX = x;
		mY = y;
	}

	float getX(){ return mX; }
	float getY(){ return mY; }

	void setX(float x){ mX = x; }
	void setY(float y){	mY = y;	}

	//Addition of two vectors
	Vector2D operator+(const Vector2D& v2) const
	{
		return Vector2D(mX + v2.mX, mY + v2.mY);
	}

	friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2)
	{
		v1.mX += v2.mX;
		v1.mY += v2.mY;
		return v1;
	}

	//Subtraction of two vectors
	Vector2D operator-(const Vector2D& v2) const
	{
		return Vector2D(mX - v2.mX, mY - v2.mY);
	}

	friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2)
	{
		v1.mX -= v2.mX;
		v1.mY -= v2.mY;
		return v1;
	}

	//Multiplication of vector by scalar
	Vector2D operator*(float scalar)
	{
		return Vector2D(mX * scalar, mY * scalar);
	}

	Vector2D operator*=(float scalar)
	{
		mX *= scalar;
		mY *= scalar;
		return *this;
	}

	//Division of vector by scalar
	Vector2D operator/(float scalar)
	{
		return Vector2D(mX / scalar, mY / scalar);
	}

	Vector2D operator/=(float scalar)
	{
		mX /= scalar;
		mY /= scalar;
		return *this;
	}

private:
	float mX;
	float mY;

};

