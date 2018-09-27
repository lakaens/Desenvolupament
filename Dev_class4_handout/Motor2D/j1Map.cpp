#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Map.h"
#include <math.h>

j1Map::j1Map() : j1Module(), map_loaded(false)
{
	name.create("map");
}

// Destructor
j1Map::~j1Map()
{}

// Called before render is available
bool j1Map::Awake(pugi::xml_node& config)
{
	LOG("Loading Map Parser");
	bool ret = true;

	folder.create(config.child("folder").child_value());

	return ret;
}

void j1Map::Draw()
{
	if(map_loaded == false)
		return;

	// TODO 6: Iterate all tilesets and draw all their 
	// images in 0,0 (you should have only one tileset for now)
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.h = 199;
	rect.w = 265;
	p2List_item<TileSet*>* item = tilesetdata.start;
	while (item != nullptr)
	{
		App->render->Blit(item->data->texture, 0, 0, &rect);
		item = item->next;
	}

}

// Called before quitting
bool j1Map::CleanUp()
{
	LOG("Unloading map");

	// TODO 2: Make sure you clean up any memory allocated
	// from tilesets / map
	

	map_file.reset();

	return true;
}

// Load new map
bool j1Map::Load(const char* file_name)
{
	bool ret = false;
	p2SString tmp("%s%s", folder.GetString(), file_name);

	pugi::xml_parse_result result = map_file.load_file(tmp.GetString());
	pugi::xml_node loadmap;


	if(result == NULL)
	{
		LOG("Could not load map xml file %s. pugi error: %s", file_name, result.description());
		ret = false;
	}
	if (result == true) {
		loadmap = map_file.child("map");
		ret = true;
		if (ret == true)
		{
			// TODO 3: Create and call a private function to load and fill
			// all your map data
			LoadMapdata(loadmap);
		}

		// TODO 4: Create and call a private function to load a tileset
		// remember to support more any number of tilesets!
		LoadTileSet(loadmap);

		if (ret == true)
		{
			p2List_item<TileSet*>* item = tilesetdata.start;
			while (item != NULL)
			{
				// TODO 5: LOG all the data loaded
				// iterate all tilesets and LOG everything
				TileSet* s = item->data;
				LOG("Successfully parsed map XML file: %s", file_name);
				LOG("width: %d height: %d", mapdata.width, mapdata.height);
				LOG("tile_width: %d tile_height: %d", mapdata.tilewidth, mapdata.tileheight);
				item = item->next;
			}
		}
	}
	map_loaded = ret;

	return ret;
}

bool j1Map::LoadMapdata(pugi::xml_node& node) 
{
	p2SString rorder = node.attribute("renderorder").as_string();
	if (rorder == "right-down"){
		mapdata.renderorder = renderorder::right_down;
	}
	else if (rorder == "right-up") {
		mapdata.renderorder = renderorder::right_up;
	}
	else if (rorder == "left-down") {
		mapdata.renderorder = renderorder::left_down;
	}
	else if (rorder == "left-up") {
		mapdata.renderorder = renderorder::left_up;
	}

	p2SString orientation = node.attribute("orientation").as_string();
	if (orientation == "orthogonal") {
		mapdata.orientation = orientation::orthogonal;
	}
	else if (orientation == "isometric") {
		mapdata.orientation = orientation::isometric;
	}
	else if (orientation == "scalatedisometric") {
		mapdata.orientation = orientation::scalatedisometric;
	}
	else if (orientation == "hexagonal") {
		mapdata.orientation = orientation::hexagonal;
	}
	mapdata.width = node.attribute("width").as_uint();
	mapdata.height = node.attribute("height").as_uint();
	mapdata.tilewidth = node.attribute("tilewidth").as_uint();
	mapdata.tileheight = node.attribute("tileheight").as_uint();
	return true;
}

bool j1Map::LoadTileSet(pugi::xml_node& node){

	TileSet* tilset_data = new TileSet;
	tilesetdata.add(tilset_data);
	p2List_item<TileSet*>* item = tilesetdata.start;

for (node.child("tileset"); node; node = node.next_sibling("tileset"))
{
		item->data->margin  = node.attribute("tilewidth").as_uint();
		item->data->margin  = node.attribute("tileheight").as_uint();
		item->data->margin  = node.attribute("spacing").as_uint();
		item->data->margin  = node.attribute("margin").as_uint();
		item->data->texture = App->tex->Load("maps/tmw_desert_spacing.png");
		return true;
	}
}

