﻿#ifndef __CORE_SLOT_H__
#define __CORE_SLOT_H__

#include "../DragonBones.h"
#include "Object.h"
#include "../objects/SlotData.h"
#include "Armature.h"

NAME_SPACE_DRAGON_BONES_BEGIN
class Slot : public Object
{
    friend class Armature;
    friend class Bone;
    
    friend class BaseFactory;
    
protected:
    bool _isShowDisplay;
    int _displayIndex;
    float _originZOrder;
    float _tweenZOrder;
    float _offsetZOrder;
    
    // <displayOrArmature*, DisplayType>
    std::vector<std::pair<void *, DisplayType>> _displayList;
    
    SlotData *_slotData;
    void *_display;
    Armature *_childArmature;
    
public:
    virtual int getDisplayIndex() const;
    
    virtual void setDisplay(void *display, const DisplayType &displayType, bool disposeExisting);
    
    virtual float getZOrder() const;
    virtual void setZOrder(float zorder);
    
    virtual const std::vector<std::pair<void *, DisplayType>> &getDisplayList() const;
    virtual void setDisplayList(const std::vector<std::pair<void *, DisplayType>> &displayList, bool disposeExisting);
    
    virtual Armature *getChildArmature() const;
    virtual void setChildArmature(Armature *childArmature, bool disposeExisting);
    
    virtual void setVisible(bool vislble) override;
    
protected:
    virtual void setArmature(Armature *armature) override;
    
public:
    Slot(SlotData *slotData);
    virtual ~Slot();
    virtual void dispose() override;
    
protected:
    virtual void update();
    virtual void changeDisplay(int displayIndex);
    virtual void updateSlotDisplay(bool disposeExisting);
    virtual void updateChildArmatureAnimation();
    
    virtual int getDisplayZIndex() const = 0;
    virtual void addDisplayToContainer(void *container, int zIndex) = 0;
    virtual void removeDisplayFromContainer() = 0;
    virtual void disposeDisplayList() = 0;
    virtual void updateDisplay(void *display, bool disposeExisting) = 0;
    virtual void updateDisplayBlendMode(const BlendMode &blendMode) = 0;
    virtual void updateDisplayColor(int aOffset, int rOffset, int gOffset, int bOffset, float aMultiplier, float rMultiplier, float gMultiplier, float bMultiplier) = 0;
    virtual void updateDisplayVisible(bool visible) = 0;
    virtual void updateDisplayTransform() = 0;
    
private:
    DRAGON_BONES_DISALLOW_COPY_AND_ASSIGN(Slot);
};
NAME_SPACE_DRAGON_BONES_END
#endif  // __CORE_SLOT_H__
