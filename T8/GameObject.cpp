#include "GameObject.h"


GameObject::GameObject(const CellPosition & pos)
{
	position = pos; // Sets Position
}
void GameObject::SetPosition(const CellPosition & pos)
{
position=pos;


}     
CellPosition GameObject::GetPosition() const
{
	return position;
}
bool GameObject::IsOverlapping(GameObject* newobj)
{
	return true;
}

GameObject::~GameObject()
{
}