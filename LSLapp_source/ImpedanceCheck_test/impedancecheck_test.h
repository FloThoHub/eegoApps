#define EEGO_SDK_BIND_STATIC // How to bind

#pragma once

#include <QtWidgets/QWidget>
#include <QSlider>
#include "ui_impedancecheck_test.h"

#include <eemagine\sdk\factory.h>
#include <lsl_cpp.h>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/foreach.hpp>


const float MIN_VALUE = 0;
const float MAX_VALUE = 100;

using namespace std;
class ImpedanceCheck_test : public QWidget
{
    Q_OBJECT

private:
	Ui::ImpedanceCheck_testClass ui;

	
	
	eemagine::sdk::amplifier* amp;
	eemagine::sdk::amplifier* amp2;
	eemagine::sdk::stream* impStream;
	eemagine::sdk::stream* eegStream;
	std::vector<std::string> channelLabels;
	

public:
    ImpedanceCheck_test(QWidget *parent = Q_NULLPTR);
	~ImpedanceCheck_test();
	bool done = false;
	bool streamImpLSL = true;
	bool stopEEG = false;
	bool closeALL = false;
	int Newframesize;
	int NewSpacerValue;
	int NewFontSize;
	int samplingRate;



	void streamEEG(int samplingRate);


	QSlider* m_slider = new QSlider(Qt::Horizontal, this);
	QLabel *labelFramesize = new QLabel(this);

	QSlider* spacer_slider = new QSlider(Qt::Horizontal, this);
	QLabel *labelSpacer = new QLabel(this);

	QSlider* fontsize_slider = new QSlider(Qt::Horizontal, this);
	QLabel *labelfontsize = new QLabel(this);


private slots:
	void setButton();
	void resetGUIButton();
	void updateFramesize(int newframesize);
	void updateSpacerValue(int newspacervalue);
	void updateFontSize(int newfontsize);
	//void streamImpedance(int NumberOfChannels);
	void enableEEG();
	void stopstreamEEG();
	void closeEvent(QCloseEvent *event);

};
