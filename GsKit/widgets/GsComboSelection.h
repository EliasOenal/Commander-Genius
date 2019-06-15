/*
 * CGUIComboSelection.h
 *
 *  Created on: 26.02.2012
 *      Author: gerstrong
 */

#ifndef CGUICOMBOSELECTION_H_
#define CGUICOMBOSELECTION_H_

#include <string>
#include <memory>
#include <list>
#include <set>
#include <graphics/GsSurface.h>

#include "GsControlsManager.h"
#include "GsButton.h"
#include "GsText.h"

class CGUIComboSelection : public GsControlsManager
{
public:

    CGUIComboSelection(const std::string& text,
                       const GsRect<float> &rect,
                        const std::list<std::string>& optionsList,
                        const GsControl::Style style = Style::NONE);

	const std::string& getSelection()
    {
        return *mOLCurrent;
    }

    virtual void cycleOption();

    bool sendEvent(const InputCommand command) override;

    virtual void setSelection( const std::string& selectionText );

    void setList(const std::set<std::string> &strSet);

    virtual void processRender(const GsRect<float> &RectDispCoordFloat) override;

    void setTextColor(const GsColor &color);

    void enableButtonBorders(const bool value);

    void enableWidgetsCenteringH(const bool value);

protected:

	std::list<std::string> mOptionsList;
	std::list<std::string>::const_iterator mOLCurrent;

    std::string mFeatureText;

    std::shared_ptr<CGUIText> mpFeatureName;
    std::shared_ptr<GsButton> mpFeatureValue;
};

#endif /* CGUICOMBOSELECTION_H_ */
