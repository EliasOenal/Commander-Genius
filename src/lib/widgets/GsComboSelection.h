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
#include <graphics/GsSurface.h>

#include "GsControl.h"

//#include "sdl/extensions.h"
//#include "engine/CEvent.h"


class CGUIComboSelection : public CGUIControl
{
public:

	CGUIComboSelection( const std::string& text, const std::list<std::string>& optionsList );

	void setupButtonSurface(const std::string &optionText);

	const std::string& getSelection();

	void cycleOption();

	bool sendEvent(const InputCommands command);

	void setSelection( const std::string& selectionText );

	void setList(const char **strArray, const int numElem);

	void processLogic();

	void drawNoStyle(SDL_Rect& lRect);

	virtual void drawVorticonStyle(SDL_Rect& lRect);

	void drawGalaxyStyle(SDL_Rect& lRect);

	virtual void processRender(const GsRect<float> &RectDispCoordFloat);

protected:

	std::string mText;
	std::list<std::string> mOptionsList;
	std::list<std::string>::const_iterator mOLCurrent;

    GsSurface mTextDarkSfc;
    GsSurface mTextLightSfc;
    GsSurface mTextDisabledSfc;

	void (CGUIComboSelection::*drawButton)(SDL_Rect&);

};

#endif /* CGUICOMBOSELECTION_H_ */
