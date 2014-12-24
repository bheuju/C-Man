/* ======================= Loader Params =========================
 This class holds an values we need when creating our object
 ---------------------------------------------------------------- 
 This class is passed into constructor of our objects. It takes
 values into its constructor and sets them as member variables
 that can be accessed to set the initial values of objects.
================================================================= */

#pragma once
#include <iostream>
#include <string>

class LoaderParams
{
public:
	LoaderParams(std::string texID, int x, int y, int width, int height, int row, int frame)
	{
		mTexID = texID;
		
		mX = x;
		mY = y;

		mWidth = width;
		mHeight = height;

		mRow = row;
		mFrame = frame;
	}

	int getX() const
	{
		return mX;
	}

	int getY() const
	{
		return mY;
	}

	int getWidth() const
	{
		return mWidth;
	}

	int getHeight() const
	{
		return mHeight;
	}

	int getRow() const
	{
		return mRow;
	}

	int getFrame() const
	{
		return mFrame;
	}

	std::string getTexID() const
	{
		return mTexID;
	}
	
private:
	int mX, mY;
	
	int mWidth, mHeight;
	
	int mRow, mFrame;

	std::string mTexID;

};

