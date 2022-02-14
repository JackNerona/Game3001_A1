#include "PlayScene.h"
#include "Game.h"
#include "EventManager.h"
#include "SoundManager.h"

// required for IMGUI
#include "imgui.h"
#include "imgui_sdl.h"
#include "Renderer.h"
#include "Util.h"

PlayScene::PlayScene()
{
	PlayScene::start();
	SoundManager::Instance();
	SoundManager::Instance().load("../Assets/audio/explosion.wav", "explosion", SOUND_SFX);
	SoundManager::Instance().load("../Assets/audio/laserShoot.wav", "laserShoot", SOUND_SFX);
}

PlayScene::~PlayScene()
= default;

void PlayScene::draw()
{
	drawDisplayList();

	SDL_SetRenderDrawColor(Renderer::Instance().getRenderer(), 255, 255, 255, 255);
}

void PlayScene::update()
{
	updateDisplayList();
}

void PlayScene::clean()
{
	removeAllChildren();
}

void PlayScene::handleEvents()
{
	EventManager::Instance().update();

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance().quit();
	}

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_1))
	{
		//Seek
		m_pTarget = new Target();
		m_pTarget->getRigidBody()->velocity = glm::vec2(0.5f, 0.0f);
		addChild(m_pTarget);

		m_pActor = new Actor();
		addChild(m_pActor);

		SoundManager::Instance().setAllVolume(8);

		SoundManager::Instance().playSound("laserShoot", 0, -1);
	}

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_2))
	{
		//Flee
		m_pTarget = new Target();
		m_pTarget->getRigidBody()->velocity = glm::vec2(0.5f, 0.0f);
		addChild(m_pTarget);

		m_pActor = new Actor();
		addChild(m_pActor);

		SoundManager::Instance().setAllVolume(8);

		SoundManager::Instance().playSound("laserShoot", 0, -1);

	}

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_3))
	{
		//Arrival
		m_pTarget = new Target();
		m_pTarget->getRigidBody()->velocity = glm::vec2(0.5f, 0.0f);
		addChild(m_pTarget);

		m_pActor = new Actor();
		addChild(m_pActor);

		SoundManager::Instance().setAllVolume(8);

		SoundManager::Instance().playSound("laserShoot", 0, -1);

	}

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_4))
	{
		//Obstacle Avoidance
		m_pTarget = new Target();
		m_pTarget->getRigidBody()->velocity = glm::vec2(0.5f, 0.0f);
		addChild(m_pTarget);

		m_pActor = new Actor();
		addChild(m_pActor);

		SoundManager::Instance().setAllVolume(8);

		SoundManager::Instance().playSound("laserShoot", 0, -1);

	}
}

void PlayScene::start()
{
	// Set GUI Title
	m_guiTitle = "Play Scene";

	//m_pTarget = new Target();
	
	SoundManager::Instance().load("../Assets/audio/rush.mp3", "rush", SOUND_MUSIC);

	SoundManager::Instance().setAllVolume(32);

	SoundManager::Instance().playMusic("rush", -1);


	/* Instructions Label */
	m_pInstructionsLabel = new Label("Press 1 to Seek, 2 to Flee, 3 for Arrival, and 4 Obstacle Avoidance", "Consolas");
	m_pInstructionsLabel->getTransform()->position = glm::vec2(Config::SCREEN_WIDTH * 0.5f, 500.0f);

	addChild(m_pInstructionsLabel);

	ImGuiWindowFrame::Instance().setGUIFunction(std::bind(&PlayScene::GUI_Function, this));
}

void PlayScene::GUI_Function() const
{
	// Always open with a NewFrame
	ImGui::NewFrame();

	// See examples by uncommenting the following - also look at imgui_demo.cpp in the IMGUI filter
	//ImGui::ShowDemoWindow();
	
	ImGui::Begin("Your Window Title Goes Here", NULL, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoMove);

	if(ImGui::Button("My Button"))
	{
		std::cout << "My Button Pressed" << std::endl;
	}
	 
	ImGui::Separator();

	static float float3[3] = { 0.0f, 1.0f, 1.5f };
	if(ImGui::SliderFloat3("My Slider", float3, 0.0f, 2.0f))
	{
		std::cout << float3[0] << std::endl;
		std::cout << float3[1] << std::endl;
		std::cout << float3[2] << std::endl;
		std::cout << "---------------------------\n";
	}
	
	ImGui::End();
}