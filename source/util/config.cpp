#include <fstream>
#include <iomanip>
#include "util/config.hpp"
#include "util/json.hpp"

namespace inst::config {
	std::string gAuthKey;
	std::string sigPatchesUrl;
	std::string httpIndexUrl;
	std::string httplastUrl;
	std::vector<std::string> updateInfo;
	int languageSetting;
	bool autoUpdate;
	bool deletePrompt;
	bool ignoreReqVers;
	bool overClock;
	bool gayMode;
	bool useSound;
	bool usbAck;
	bool validateNCAs;
	bool fixticket;
	bool listoveride;
	bool httpkeyboard;

	void setConfig() {
		nlohmann::json j = {
			{"autoUpdate", autoUpdate},
			{"deletePrompt", deletePrompt},
			{"gAuthKey", gAuthKey},
			{"gayMode", gayMode},
			{"useSound", useSound},
			{"ignoreReqVers", ignoreReqVers},
			{"languageSetting", languageSetting},
			{"overClock", overClock},
			{"sigPatchesUrl", sigPatchesUrl},
			{"usbAck", usbAck},
			{"validateNCAs", validateNCAs},
			{"httpIndexUrl", httpIndexUrl},
			{"httplastUrl", httplastUrl},
			{"fixticket", fixticket},
			{"listoveride", listoveride},
			{"httpkeyboard", httpkeyboard}
		};
		std::ofstream file(inst::config::configPath);
		file << std::setw(4) << j << std::endl;
	}

	void parseConfig() {
		try {
			std::ifstream file(inst::config::configPath);
			nlohmann::json j;
			file >> j;
			autoUpdate = j["autoUpdate"].get<bool>();
			fixticket = j["fixticket"].get<bool>();
			listoveride = j["listoveride"].get<bool>();
			httpkeyboard = j["httpkeyboard"].get<bool>();
			deletePrompt = j["deletePrompt"].get<bool>();
			gAuthKey = j["gAuthKey"].get<std::string>();
			gayMode = j["gayMode"].get<bool>();
			useSound = j["useSound"].get<bool>();
			ignoreReqVers = j["ignoreReqVers"].get<bool>();
			languageSetting = j["languageSetting"].get<int>();
			overClock = j["overClock"].get<bool>();
			sigPatchesUrl = j["sigPatchesUrl"].get<std::string>();
			httpIndexUrl = j["httpIndexUrl"].get<std::string>();
			httplastUrl = j["httplastUrl"].get<std::string>();
			usbAck = j["usbAck"].get<bool>();
			validateNCAs = j["validateNCAs"].get<bool>();
		}
		catch (...) {
			// If loading values from the config fails, we just load the defaults and overwrite the old config
			gAuthKey = { 0x41,0x49,0x7a,0x61,0x53,0x79,0x42,0x4d,0x71,0x76,0x34,0x64,0x58,0x6e,0x54,0x4a,0x4f,0x47,0x51,0x74,0x5a,0x5a,0x53,0x33,0x43,0x42,0x6a,0x76,0x66,0x37,0x34,0x38,0x51,0x76,0x78,0x53,0x7a,0x46,0x30 };
			sigPatchesUrl = "https://github.com/mrdude2478/patches/releases/download/1/patches.zip";
			languageSetting = 0;
			httpIndexUrl = "http://";
			httplastUrl = "http://";
			autoUpdate = true;
			deletePrompt = true;
			gayMode = false;
			useSound = true;
			fixticket = true;
			listoveride = false;
			httpkeyboard = false;
			ignoreReqVers = true;
			overClock = true;
			usbAck = false;
			validateNCAs = true;
			setConfig();
		}
	}
}