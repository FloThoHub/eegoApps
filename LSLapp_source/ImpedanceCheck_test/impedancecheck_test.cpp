#define EEGO_SDK_BIND_STATIC // How to bind

#include "impedancecheck_test.h"
#include <eemagine\sdk\factory.h>
//#include <eemagine\sdk\wrapper.cc>
#include <QDesktopWidget>
#include <eemagine\sdk\wrapper.cc>
#include <QApplication>
#include <QCoreApplication>
#include <QLabel>
#include <QPushButton>
#include <QTextStream>
#include <qfile.h>
#include <QString>
#include <fstream>
#include <qlayout.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>  
#include <sstream>
#include <chrono>
#include <thread>
#include <conio.h>
#include <math.h>
#include <QFileDialog>
#include <QMessageBox>
#include <QCloseEvent>
#include <QInputDialog>


using namespace lsl;
using namespace eemagine::sdk;

/*
void ImpedanceCheck_test::setButton() 
{
	done = true;
	closeALL = true;
	streamImpLSL = false;
	stopEEG = true;

}
*/

void ImpedanceCheck_test::enableEEG()
{
	done = true;
	streamImpLSL = false;
	stopEEG = false;

}

void ImpedanceCheck_test::stopstreamEEG()
{
	stopEEG = true;
}


void ImpedanceCheck_test::updateFramesize(int newframesize)
{
	Newframesize = m_slider->value();


}


void ImpedanceCheck_test::closeEvent(QCloseEvent *event)
{
	done = true;
	closeALL = true;
	streamImpLSL = false;
	stopEEG = true;
	closeEvent(event);
}

//resetGUIButton(): fits ectrode labels to window size.
void ImpedanceCheck_test::resetGUIButton()
{
	NewSpacerValue = 4;
	Newframesize = 50;
	NewFontSize = 6;
	spacer_slider->setValue(NewSpacerValue);
	m_slider->setValue(Newframesize);
	fontsize_slider->setValue(NewFontSize);

}
void ImpedanceCheck_test::updateSpacerValue(int newspacervalue)
{
	NewSpacerValue = spacer_slider->value();
}

void ImpedanceCheck_test::updateFontSize(int newfontsize)
{
	NewFontSize = fontsize_slider->value();
}

void ImpedanceCheck_test::setSamplingRate(int idx)
{

	samplingRate = samplingBox->itemText(idx).toInt();
}



ImpedanceCheck_test::ImpedanceCheck_test(QWidget *parent)
: QWidget(parent)
{
	//------------------------------------------------------------------------------------------------------------------------------------------------
	//get positions and labels from the txt file
	/*
	QMessageBox msgBox1;
	msgBox1.setWindowTitle("Notice");
	msgBox1.setText("Please make sure, that the 2D position in the .txt-file should have the following form:\n \n Fp1  82.7	32.28 \n Fpz  90  -0.1 \n Fp2       82.7 -32.38 \n \n there should be only blanks inbetween.");
	msgBox1.exec();
	*/


	QFileDialog dialog(this);
	dialog.setFileMode(QFileDialog::ExistingFile);
	dialog.setWindowTitle("Select cap-postion file (.txt or .elc)");
	//dialog.show();

	QString fileName;
	if (dialog.exec())
		fileName = dialog.getOpenFileName();



	string filestring = fileName.toStdString();
	string line;
	vector<string> text;
	QVector<QString> subinfo;
	QVector<QVector<QString>> info; // Channelnumber (Name, Xpos, Ypos)
	ifstream myfile(filestring);



	if (!myfile) //Always test the file open.
	{
		cout << "Error opening electrode position file" << endl;
		system("pause");
		
	}

	while (std::getline(myfile, line))
	{
		text.push_back(line);
	}

	for (int i = 0; i < text.size(); i++)
	{
		std::istringstream iss(text.at(i));

		do
		{
			std::string sub;
			iss >> sub;
			QString qstr = QString::fromStdString(sub);
			subinfo.push_back(qstr);
		} while (iss);

		info.push_back(subinfo);
		subinfo.clear();

	}
	
	//------------------------------------------------------------------------------------------------------------------------------------------------
	//Generate GUI

	QWidget* z = new QWidget;
	z->setWindowTitle("eego LSL App");
	QDesktopWidget desktop;
	QRect mainScreenSize = desktop.availableGeometry(desktop.primaryScreen());

	if (fileName.isEmpty() && fileName.isNull()){

		exit(EXIT_FAILURE);
	}
	
	//z->setVisible(true);

	z->setStyleSheet("background-color:gray;");

	m_slider->setMinimum(0);
	m_slider->setMaximum(60);
	m_slider->setParent(z);
	m_slider->setValue(50);
	m_slider->setGeometry(20, 50, 200, 22);
	connect(m_slider, SIGNAL(valueChanged(int)),
		this, SLOT(updateFramesize(int)));

	QFont f("Arial", 8);
	labelFramesize->setText(QString("change Framesize:"));
	QFontMetrics fm(f);
	labelFramesize->setFont(f);
	labelFramesize->setParent(z);
	labelFramesize->setGeometry(20, 30, 200, 22);
	labelFramesize->setVisible(true);

	spacer_slider->setMinimum(3);
	spacer_slider->setMaximum(5);
	spacer_slider->setParent(z);
	spacer_slider->setValue(4);
	spacer_slider->setGeometry(20, 100, 200, 22);
	connect(spacer_slider, SIGNAL(valueChanged(int)),
		this, SLOT(updateSpacerValue(int)));


	labelSpacer->setText(QString("change spacervalue:"));
	labelSpacer->setFont(f);
	labelSpacer->setParent(z);
	labelSpacer->setGeometry(20, 80, 200, 22);
	labelSpacer->setVisible(true);

	labelfontsize->setText(QString("change fontsize:"));
	labelfontsize->setFont(f);
	labelfontsize->setParent(z);
	labelfontsize->setGeometry(20, 130, 200, 22);
	labelfontsize->setVisible(true);

	fontsize_slider->setMinimum(4);
	fontsize_slider->setMaximum(9);
	fontsize_slider->setParent(z);
	fontsize_slider->setValue(6);
	fontsize_slider->setGeometry(20, 150, 200, 22);
	connect(fontsize_slider, SIGNAL(valueChanged(int)),
		this, SLOT(updateFontSize(int)));

	/*
	QPushButton *doneButton = new QPushButton(this);
	doneButton->setText("Done");
	doneButton->setParent(z);
	doneButton->setGeometry(mainScreenSize.width()-200, mainScreenSize.height() - 200, 80, 40);
	doneButton->setStyleSheet("QButton { background-color : green; color : black; }");
	connect(doneButton, SIGNAL(clicked()), this, SLOT(setButton()));
	*/

	QPushButton *resetGUIButton = new QPushButton(this);
	resetGUIButton->setText("Reset");
	resetGUIButton->setParent(z);
	resetGUIButton->setGeometry(20, 180, 80, 40);
	resetGUIButton->setStyleSheet("QButton { background-color : green; color : black; }");
	connect(resetGUIButton, SIGNAL(clicked()), this, SLOT(resetGUIButton()));
	
	/*
	QPushButton *streamImpedance = new QPushButton(this);
	streamImpedance->setText("stream Impedance to LSL");
	streamImpedance->setParent(z);
	streamImpedance->setGeometry(20, 230, 180, 40);
	streamImpedance->setStyleSheet("QButton { background-color : green; color : black; }");
	connect(streamImpedance, SIGNAL(clicked()), this, SLOT(streamImpedance()));
	*/
	QPushButton *enableEEG = new QPushButton(this);
	enableEEG->setText("stream EEG to LSL");
	enableEEG->setParent(z);
	enableEEG->setGeometry(20, 280, 180, 40);
	enableEEG->setStyleSheet("QButton { background-color : green; color : black; }");
	connect(enableEEG, SIGNAL(clicked()), this, SLOT(enableEEG()));

	QPushButton *stopstreamEEG = new QPushButton(this);
	stopstreamEEG->setText("Stop EEG stream");
	stopstreamEEG->setParent(z);
	stopstreamEEG->setGeometry(20, 330, 180, 40);
	stopstreamEEG->setStyleSheet("QButton { background-color : green; color : black; }");
	connect(stopstreamEEG, SIGNAL(clicked()), this, SLOT(stopstreamEEG()));


	//-----------------------------------------------------------------------------------------------------------------------------
	//Place lables according to txt-file data
	QVector<QLabel*> labels;
	
	z->adjustSize();

		double offsetX = (mainScreenSize.width() / 2)+50;
		double offsetY = (mainScreenSize.height() / 2-100);
		double spacer = -3.5;

		int framesize = 1;


		for (int i = 0; i <= info.size() - 1; i++)
		{
			
			labels.append(new QLabel);
			QString tmp = info.at(i).at(0);
			channelLabels.push_back(info.at(i).at(0));
			QString value = " inf";
			
			labels[i]->setText(QString("<font size=3>") + tmp +
				"</font><br><font size=" + Newframesize/10 + ">" + value + "</font>");
			labels[i]->setParent(z);
			double Xpos = info.at(i).at(1).toDouble(false);
			double Ypos = info.at(i).at(2).toDouble(false);
			labels[i]->setGeometry(offsetX + Ypos*spacer, offsetY + Xpos*spacer, framesize, framesize);
			labels[i]->setStyleSheet("QLabel { background-color : white; color : black; }");

		}

	
		z->hide();
		z->adjustSize();
		z->show();
		//---------------------------------------------------------------------------------------------------------------

	
	NewSpacerValue = 5;
	Newframesize = 50;
	NewFontSize = 6;

	QString tmp;
	QString value;
	double newspacer;
	double Xpos;
	double Ypos;
	double Ohm;

	//no amp pluged in testing
	/*
	while (done == false)
	{

		qApp->processEvents(QEventLoop::AllEvents);


		for (int i = 0; i <= info.size() - 1; i++)
		{

			
			tmp = info.at(i).at(0);
			value = " inf";
			QFont f("Arial", NewFontSize);
			QFontMetrics fm(f);
			labels[i]->setFont(f);
			labels[i]->setAlignment(Qt::AlignCenter);
			labels[i]->setText(tmp + "<br>" + value );
			labels[i]->setParent(z);
			newspacer = (double)NewSpacerValue;
			newspacer = -newspacer;
			Xpos = info.at(i).at(1).toDouble(false);
			Ypos = info.at(i).at(2).toDouble(false);
			labels[i]->setGeometry(offsetX + Ypos*newspacer, offsetY + Xpos*newspacer, Newframesize, Newframesize);
			labels[i]->setStyleSheet("QLabel { background-color : white; color : black; }");

		}

	}
	
	*/

	//------------------------------------------------------------------------------------------------------------------------------------------------
	// eego Amp setup

	
	using namespace eemagine::sdk;
	try {
		while (closeALL == false)
		{
			factory fact("eego-SDK.dll");

			if (fact.getAmplifiers().empty())
			{
				QMessageBox errorBox;
				errorBox.setWindowTitle("Error: Amp not found");
				errorBox.setText("Please connect the amplifier and make sure that the amp is turned on, then restart the app.");
				errorBox.exec();
				done = true;
				z->close();

			}
			amplifier* amp = fact.getAmplifier(); // Get an amplifier

			stream* impedanceStream = amp->OpenImpedanceStream();
			buffer buf = impedanceStream->getData();

			//LSL
			stream_info impStream("ImpedanceStream", "Impedance", info.size(), 100);


			// add some description fields
			impStream.desc().append_child_value("manufacturer", "ANT");
			lsl::xml_element chns = impStream.desc().append_child("channels");
			for (int k = 0; k < info.size(); k++)
				chns.append_child("channel")
				.append_child_value("label", channelLabels.at(k).toUtf8().constData())
				.append_child_value("unit", "Ohm")
				.append_child_value("type", "Impedance");
			//
			stream_outlet outlet(impStream);


			while (streamImpLSL == true)
			{
				qApp->processEvents(QEventLoop::AllEvents);
				buffer buf = impedanceStream->getData();
				double* impedanceData = buf.data();
				for (int i = 0; i < info.size(); i++)
				{
					Ohm = impedanceData[i];


					double starttime = ((double)clock()) / CLOCKS_PER_SEC;

					tmp = info.at(i).at(0);
					//value = " inf";
					value = QString("%1").arg(Ohm, 0, 'E', 1);
					QFont f("Arial", NewFontSize);
					QFontMetrics fm(f);
					labels[i]->setFont(f);
					labels[i]->setAlignment(Qt::AlignCenter);
					labels[i]->setText(tmp + "<br>" + value);
					labels[i]->setParent(z);
					newspacer = (double)NewSpacerValue;
					newspacer = -newspacer;
					Xpos = info.at(i).at(1).toDouble(false);
					Ypos = info.at(i).at(2).toDouble(false);
					labels[i]->setGeometry(offsetX + Ypos*newspacer, offsetY + Xpos*newspacer, Newframesize, Newframesize);
					labels[i]->setStyleSheet("QLabel { background-color : white; color : black; }");
					

					//coloring labels according to Impedance value in Ohm
					if (impedanceData[i] >= 150000)//inf, white
					{
						labels[i]->setStyleSheet("QLabel { background-color : white; color : black; }");
					}
					else if (impedanceData[i] <= 150000 && impedanceData[i] >= 100000)//too high, red
					{
						labels[i]->setStyleSheet("QLabel { background-color : red; color : black; }");
					}
					else if (impedanceData[i] <= 100000 && impedanceData[i] >= 50000)//high, orange
					{
						labels[i]->setStyleSheet("QLabel { background-color : orange; color : black; }");
					}
					else if (impedanceData[i] <= 50000 && impedanceData[i] >= 20000)//okay, yellow
					{
						labels[i]->setStyleSheet("QLabel { background-color : yellow; color : black; }");
					}
					else if (impedanceData[i] <= 20000)// good, green
					{
						labels[i]->setStyleSheet("QLabel { background-color : green; color : black; }");
					}
				}
				//if (streamImpLSL == true)
				//{
				outlet.push_sample(impedanceData); //push vector with impedance data to LSL
				//}


			}



			// Make sure to delete the amplifier objects to release resources
			impedanceStream->~stream();
			amp->~amplifier();
			fact.~factory();
			delete impedanceStream;
			delete amp; 

			//starts EEG stream if button was clicked
			if (stopEEG == false)
			{
				bool ok;
				samplingRate = QInputDialog::getInt(this, tr("Choose samplingrate"),
					tr("Samplingrate:"), 128, 256, 512, 1024, &ok);

				ImpedanceCheck_test::streamEEG(samplingRate);
				streamImpLSL = true;//restart Impedance stream 

				QMessageBox errorBox;
				errorBox.setWindowTitle("LLS app");
				errorBox.setText("EEG stream stopped, impedance stream up again");
				errorBox.exec();
			}


		}
	}
	catch (exceptions::notConnected)
	{
		QMessageBox errorBox;
		errorBox.setWindowTitle("Error: Amp not connected");
		errorBox.setText("Amp not found or licence file not present. Please connect the amplifier and make sure that the amp is turned on and a license file is present in 'Documents/eego/'");
		errorBox.exec();
		exit(EXIT_FAILURE);
		qApp->quit();
	}


	QMessageBox errorBox;
	errorBox.setWindowTitle("LSL app");
	errorBox.setText("Finished!");
	errorBox.exec();
	exit(EXIT_FAILURE);

	qApp->quit();
	
	//------------------------------------------------------------------------------------------------------------------------------------------------


}
/*
void ImpedanceCheck_test::streamImpedance(int NumberOfChannels)
{
	streamImpLSL = true;
}
*/

// Streams EEG to LSL, code copied from github eegosports repo
void ImpedanceCheck_test::streamEEG(int samplingRate)
{
	QMessageBox errorBox;
	errorBox.setWindowTitle("LSL");
	errorBox.setText("Amp is now streaming EEG-data to LSL.");
	errorBox.exec();

		factory fact("eego-SDK.dll");
		amp2 = fact.getAmplifier();
		eegStream = amp2->OpenEegStream(samplingRate);

		std::vector<channel> channelList = eegStream->getChannelList();

		// create data streaminfo and append some meta-data
		lsl::stream_info data_info("EEGstreamANTNeuro " + amp2->getSerialNumber(), "EEG", channelList.size() - 2, samplingRate, lsl::cf_float32, "eegoSports_" + amp2->getSerialNumber());
		lsl::xml_element channels = data_info.desc().append_child("channels");

		for (int k = 0; k < channelList.size() - 2; k++) {
			channels.append_child("channel")
				.append_child_value("label", channelLabels.at(k).toUtf8().constData())
				.append_child_value("type", "EEG")
				.append_child_value("unit", "microvolts");
		}
		data_info.desc().append_child("acquisition")
			.append_child_value("manufacturer", "antneuro")
			.append_child_value("serial_number", boost::lexical_cast<std::string>(amp2->getSerialNumber()).c_str());

		// make a data outlet
		lsl::stream_outlet data_outlet(data_info);

		// create marker streaminfo and outlet
		lsl::stream_info marker_info("eegoSports-" + amp2->getSerialNumber() + "_markers" + "Markers", "Markers", 1, 0, lsl::cf_string, "eegoSports_" + boost::lexical_cast<std::string>(amp2->getSerialNumber()) + "_markers");
		lsl::stream_outlet marker_outlet(marker_info);

		std::vector<channel> eegChannelList = eegStream->getChannelList();

		int timeout_count = 0;
		while (stopEEG == false) {
			qApp->processEvents(QEventLoop::AllEvents);
			buffer buffer = eegStream->getData();
			int channelCount = buffer.getChannelCount();
			int sampleCount = buffer.size() / channelCount;
			std::vector<std::vector<float>> send_buffer(sampleCount, std::vector<float>(channelCount - 2));
			for (int s = 0; s < sampleCount; s++) {
				for (int c = 0; c < channelCount - 2; c++) {
					send_buffer[s][c] = buffer.getSample(c, s);
				}
			}
			double now = lsl::local_clock();
			data_outlet.push_chunk(send_buffer, now);

			int last_mrk = 0;
			for (int s = 0; s < sampleCount; s++) {
				//if (int mrk = src_buffer[channelCount + s*(channelCount + 1)]) {
				int mrk = buffer.getSample(channelCount - 2, s);
				if (mrk != last_mrk) {
					std::string mrk_string = boost::lexical_cast<std::string>(mrk);
					marker_outlet.push_sample(&mrk_string, now + (s + 1 - sampleCount) / samplingRate);
					last_mrk = mrk;
				}
			}
		}

		delete eegStream;

		delete amp2; // Make sure to delete the amplifier objects to release resources
	}


//destructor
ImpedanceCheck_test::~ImpedanceCheck_test()
{

}



