#pragma once

class Wheel
{
public:
	void SetRadius(float radius) { this->radius = radius; }
	float GetRadius() { return radius; }

private:
	float radius;
};

class Handle
{
public:
	void SetSize(size_t size) { this->size = size; }
	size_t GetSize() { return size; }

private:
	size_t size;
};

class CarBody
{
public:
	enum class SizeType
	{
		small,
		middle,
		big
	};
	void SetSizeType(SizeType size_type) { this->size_type = size_type; }
	SizeType GetSizeType() { return size_type; }

private:
	SizeType size_type;
};