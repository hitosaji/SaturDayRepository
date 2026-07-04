#pragma once
class Map
{
private:
	//  The x position of the object in the world
	float worldX;
	float worldY;
public:

	Map(float worldX, float worldY);

	void Draw(float cameraX);

};

