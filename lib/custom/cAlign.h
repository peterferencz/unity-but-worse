#pragma once

#include "object/components/cBehaviour.h"
#include "object/components/cTransform2D.h"
#include "object/components/cScreenView.h"

enum HorizontalAlignment { Left, Center, Right };
enum VerticalAlignment { Top, Middle, Bottom };

class cAlign : public cBehaviour {
private:
    cTransform2D* _transform;
    cScreenView* _screenView;

    HorizontalAlignment _ha;
    VerticalAlignment _va;

public:
    cAlign(HorizontalAlignment const& ha = HorizontalAlignment::Center, VerticalAlignment const& va = VerticalAlignment::Middle);
    ~cAlign();

    void onAwake() override;
    void onStart() override;
    void onUpdate() override;
};

