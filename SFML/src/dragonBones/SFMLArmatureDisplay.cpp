/** @file SFMLArmatureDisplay.cpp
 ** @author Piotr Krupa (piotrkrupa06@gmail.com)
 ** @license MIT License
 **/

#include "SFMLArmatureDisplay.h"

#include <SFML/Graphics/RenderTarget.hpp>

#include "SFMLArmatureProxy.h"
#include "SFMLSlot.h"

DRAGONBONES_NAMESPACE_BEGIN

SFMLArmatureDisplay::SFMLArmatureDisplay(const std::string& armatureName, const std::string& dragonBonesName, const std::string& skinName, const std::string& textureAtlasName)
{
	_proxy = SFMLFactory::get()->buildArmatureDisplay(armatureName, dragonBonesName, skinName, textureAtlasName);
}

SFMLArmatureDisplay::~SFMLArmatureDisplay()
{
	_proxy->dispose(true);
	_proxy = nullptr;
}

Armature* SFMLArmatureDisplay::getArmature() const
{
	if (_proxy)
		return _proxy->getArmature();

	return nullptr;
}

Animation* SFMLArmatureDisplay::getAnimation() const
{
	if (_proxy)
		return _proxy->getAnimation();

	return nullptr;
}

SFMLEventDispatcher* SFMLArmatureDisplay::getEventDispatcher()
{
	if (_proxy)
		return _proxy->getEventDispatcher();

	return nullptr;
}

SFMLArmatureProxy* SFMLArmatureDisplay::getArmatureProxy() const
{
	return _proxy;
}

sf::FloatRect SFMLArmatureDisplay::getBoundingBox()
{
	if (_proxy)
		return _proxy->getBoundingBox();

	return sf::FloatRect();
}

void SFMLArmatureDisplay::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.translate(_pos);

	if (_proxy)
		target.draw(*_proxy, states);
}

void SFMLArmatureDisplay::drawSlot(sf::RenderTarget& target, sf::RenderStates states, std::string name) const
{
	SFMLSlot* slot = (SFMLSlot*)getArmature()->getSlot(name);
	if (!slot) return;
	SFMLNode* display = slot->getDisplayNode();
	if (!display) return;
	//display->position = _position;

	bool wasVisible = display->getVisible();
	display->setVisible(true);
	target.draw(*display, states);
	display->setVisible(wasVisible);
}

DRAGONBONES_NAMESPACE_END
