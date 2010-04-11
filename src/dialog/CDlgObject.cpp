/*
 * CDlgObject.cpp
 *
 *  Created on: 19.08.2009
 *      Author: gerstrong
 */

#include "CDlgObject.h"
#include "../graphics/CFont.h"

CDlgObject::CDlgObject(){
	m_selectable = false;
	m_Option = NULL;
}

///
// Creation Routine
///
void CDlgObject::create(Uint8 type, Uint16 ID, Uint16 x, Uint16 y, const std::string &text, unsigned int delimiter)
{
	m_type = type;
	m_ID = ID;
	
	m_x = x;
	m_y = y;
	
	if( m_type == DLG_OBJ_OPTION_TEXT || m_type == DLG_OBJ_DISABLED || m_type == DLG_OBJ_TEXT )
	{
		m_selectable = (m_type == DLG_OBJ_OPTION_TEXT) ? true : false;
		m_Option = new CDlgOptionText(text, delimiter);
	}
}

void CDlgObject::change(unsigned int delimiter, const std::string &text, Uint8 type)
{
	m_type = type;
	if( m_type == DLG_OBJ_OPTION_TEXT || m_type == DLG_OBJ_DISABLED)
	{
		m_selectable = (m_type == DLG_OBJ_OPTION_TEXT) ? true : false;
		m_Option->setText(text, delimiter);
	}
	else if( m_type == DLG_OBJ_TEXT )
	{
		m_selectable = false;
		m_Option->setText(text, delimiter+4);
	}
}

///
// Property change routine
///

///
// Rendering Routine
///
void CDlgObject::render(SDL_Surface *dst, Uint8 scrollamt, bool highlight)
{
	if(m_type == DLG_OBJ_OPTION_TEXT)
		m_Option->draw(dst, m_x+16, m_y-8*scrollamt, highlight); // +16 because selection icon needs space
	else if(m_type == DLG_OBJ_DISABLED)
		m_Option->draw(dst, m_x+16, m_y-8*scrollamt, highlight); // +16 because selection icon needs space
	else if(m_type == DLG_OBJ_TEXT)
		m_Option->draw(dst, m_x, m_y-8*scrollamt, true);
}

///
// Erase Routine
///
CDlgObject::~CDlgObject(){
	if( m_type == DLG_OBJ_OPTION_TEXT || m_type == DLG_OBJ_DISABLED || m_type == DLG_OBJ_TEXT )
	{
		if(m_Option) delete m_Option;
	}
}
