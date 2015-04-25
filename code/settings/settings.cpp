/**************************** settings.cpp ***************************

Dialog to select program settings

Copyright (C) 2013-2014
by: Andrew J. Bibb
License: MIT 

Permission is hereby granted, free of charge, to any person obtaining a copy 
of this software and associated documentation files (the "Software"),to deal 
in the Software without restriction, including without limitation the rights 
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
copies of the Software, and to permit persons to whom the Software is 
furnished to do so, subject to the following conditions: 

The above copyright notice and this permission notice shall be included 
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
DEALINGS IN THE SOFTWARE.
***********************************************************************/ 


# include <QtCore/QDebug>

# include "./code/settings/settings.h"
# include "./code/resource.h"

// constructor
// Most of the interface is defined in the ui
Settings::Settings(QWidget *parent)
    : QDialog(parent)
{	
  // setup the user interface
  ui.setupUi(this);	
  
  // read the settings
  settings = new QSettings(ORG, APP, this);
  
	settings->beginGroup("Preferences");
	usesettings = settings->value("retain_settings").toBool();
	usestate = settings->value("retain_state").toBool();
	useplaylist = settings->value("retain_playlist").toBool();
	settings->endGroup();

	settings->beginGroup("StartOptions");
	QIcon::setThemeName(settings->value("icon_theme").toString() );
	settings->endGroup();
	  
}  

// Slot to save GUI settings to disk
void Settings::writeSettings()
{
  settings->beginGroup("Preferences");
  settings->setValue("retain_settings", ui.checkBox_retainsettings->isChecked() );
  settings->setValue("retain_state", ui.checkBox_retainstate->isChecked() );
  settings->setValue("retain_playlist", ui.checkBox_playlist->isChecked() );
  settings->endGroup();

  settings->beginGroup("StartOptions");
  settings->setValue("use_stream_buffering", ui.checkBox_streambuffering->isChecked() );
  settings->setValue("use_connection_speed", ui.checkBox_connectionspeed->isChecked() );
  settings->setValue("connection_speed", ui.spinBox_connectionspeed->value() );
  settings->setValue("use_download_buffering", ui.checkBox_downloadbuffering->isChecked() );
  settings->setValue("start_fullscreen", ui.checkBox_fullscreen->isChecked() );
	settings->setValue("start_gui", ui.checkBox_gui->isChecked() );
  
  settings->setValue("icon_theme", QIcon::themeName() );
  settings->endGroup();
  
  return;
}

//
// Slot to save the geometry of a window
void Settings::saveElementGeometry(const QString& elem, const bool& vis, const QSize& size, const QPoint& point)
{
	settings->beginGroup("State");
	settings->setValue(QString("%1_vis").arg(elem), vis);
	settings->setValue(QString("%1_size").arg(elem), size);
	settings->setValue(QString("%1_pos").arg(elem), point);
	settings->endGroup();
}

//
// Slot to restore the geometry of a window
void Settings::restoreElementGeometry(const QString& elem, QWidget* win)
{
	settings->beginGroup("State");	
	if (settings->value(QString("%1_vis").arg(elem)).toBool() ) {
		win->show();
		win->resize(settings->value(QString("%1_size").arg(elem)).toSize() );
		win->move(settings->value(QString("%1_pos").arg(elem)).toPoint() );
	}
	settings->endGroup();
}





