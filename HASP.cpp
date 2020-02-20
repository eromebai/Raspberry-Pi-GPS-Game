#include "HASP.h"

using namespace std;

	HASP::HASP(){}
	
	HASP::~HASP(){
		delete lightManager;
		delete buttonManager;
		delete gps;
	}
	
	void HASP::start_game(){
		buttonManager = new ButtonManager();
		lightManager = new LightManager();
		gps = new GPSHandler();
		lightManager->updateState(1);
		printf("start_game\n");
		thread button(&ButtonManager::ButtonThread, buttonManager);
		buttonManager->clickedEvent.bind(&HASP::nextStage, this);
		buttonManager->heldEvent.bind(&HASP::end_game, this);
		button.join();
	}
	
	void HASP::set_object_location(){
		printf("set_object_loca\n");
		object_location = gps->GetCoordinates();
		lightManager->updateState(2);
		cout << "destination " << object_location.x << ", " << object_location.y << endl;

	}
	
	void HASP::set_start_location_time_and_searching(){
		printf("set_start_time_location_and_start_searching\n");
		start_time = time(0);
		start_location = gps->GetCoordinates();
		cout << "start_location " << start_location.x << ", " << start_location.y << endl;
		lightManager->updateState(3);
		jump = 0;
		thread stage3loop(&HASP::loop, this);
		stage3loop.detach();
	}
	
	void HASP::player1_end(){
		printf("player1 end\n");
		jump = 1;
		end_time = time(0);
		player1_timeUse = end_time - start_time;
	}
	
	void HASP::player2_start(){
		lightManager->updateState(1);
	}
	
	void HASP::player2_end(){
		printf("end game\n");
		jump = 1;
		lightManager->updateState(4);
		end_time = time(0);
		player2_timeUse = end_time - start_time;
		fp = fopen("output.txt", "w");
		fprintf(fp, "first player: %ld:%ld:%ld\n", player1_timeUse/60/60, player1_timeUse/60, player1_timeUse%60);
		fprintf(fp, "second player: %ld:%ld:%ld\n", player2_timeUse/60/60, player2_timeUse/60, player2_timeUse%60);
		fclose(fp);
		buttonManager->Kill();
	}
	
	void HASP::end_game(){
		jump = 999;
		lightManager->updateState(4);
		buttonManager->Kill();
	}
	
	void HASP::nextStage(){
		if((process == 2 || process == 6) && distance_percentage*100 > 15){
			return;
		}
		printf("next_stage\n");
		process++;
		switch(process){
			case 1: set_object_location();							break;
			case 2: set_start_location_time_and_searching();		break;
			case 3: player1_end();									break;
			case 4: player2_start();								break;
			case 5:	set_object_location();							break;
			case 6: set_start_location_time_and_searching();		break;
			case 7: player2_end();									break;
			default: printf("process out of bound.\n");				break;
		}
	}
	
	void HASP::loop(){
		while(jump == 0){
			delay(1000);

			current_location = gps->GetCoordinates();
			long double thisToDest = gps->CalculateDistance(current_location, object_location);
			long double startToDest = gps->CalculateDistance(start_location, object_location);
			cout << "start " << start_location.x << ", " << start_location.y << endl;
			cout << "destination " << object_location.x << ", " << object_location.y << endl;
			cout << "current " << current_location.x << ", " << current_location.y << endl;
			if (startToDest == 0){
				cerr << "dividing by zero" << endl;
				exit(1);
			}
			cout << "thisToDest: " << thisToDest << " startToDest: " << startToDest << endl; 
			distance_percentage = thisToDest / startToDest;
			distance_percentage = 100*distance_percentage;
			cout << "%" << distance_percentage <<endl;
			
			lightManager->updateDistance(distance_percentage);
		}
	}
	
	
	
	
	
	
		
		
		
		
		
		
		
		
		
		
