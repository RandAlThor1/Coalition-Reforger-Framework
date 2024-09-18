[ComponentEditorProps(category: "Gear Script Component", description: "")]
class CRF_GearScriptPlayerComponentClass: ScriptComponentClass
{
	
}

class CRF_GearScriptPlayerComponent: ScriptComponent
{
	//------------------------------------------------------------------------------------------------

	// override/static functionss

	//------------------------------------------------------------------------------------------------
	
	static CRF_GearScriptPlayerComponent GetInstance()
	{
		if (GetGame().GetPlayerController())
			return CRF_GearScriptPlayerComponent.Cast(GetGame().GetPlayerController().FindComponent(CRF_GearScriptPlayerComponent));
		else
			return null;
	}
	
	//------------------------------------------------------------------------------------------------
	override protected void OnPostInit(IEntity owner) 
	{
		/*
		super.OnPostInit(owner);
		
		SCR_FactionManager factionManager = SCR_FactionManager.Cast(GetGame().GetFactionManager());
		Faction faction = factionManager.GetPlayerFaction(SCR_PlayerController.GetLocalPlayerId());
		int FactionID = getFactionID(faction.ToString());
		CRF_GearScriptModeComponent GearScriptMode = CRF_GearScriptModeComponent.cast(GetGame().GetGameMode().FindComponent(CRF_GearScriptModeComponent));
		CRF_GearScriptConfig GearScript = GearScriptMode.getFactionConfig(FactionID);
		GearScripStart(GearScript);
		*/

	}
	
	
	void GearScripStart(CRF_GearScriptConfig GearScript){
		/*
		IEntity weapon = GearScript.m_DefaultGearSettings.m_PrimaryWeapon;
		IEntity weaponSpawned = GetGame().SpawnEntityPrefab(Resource.Load(weapon), null, null);
		SCR_CharacterControllerComponent characterController = SCR_CharacterControllerComponent.Cast(GetGame().GetPlayerController().FindComponent(SCR_CharacterControllerComponent));
		InventoryStorageManagerComponent inventoryStorageManager = characterController.GetInventoryStorageManager();
		*/
		/*
		inventoryStorageManager.TryInsertItemInStorage(weapon, inventoryStorageManager.FindStorageForItem(weapon, EStoragePurpose.PURPOSE_WEAPON_PROXY));
		// Send an RPC to the client to equip the new weapon
		IEntity wec = (player.FindComponent(WeaponEquipComponent));
		GetGame().GetCallqueue().CallLater(wec.setWeapon, 0, false, player, weapon);
		*/
	}
	
	
	int getFactionID(string fact){
		if (fact == "BLUFOR") return 0;
		else if(fact == "OPFOR") return 1;
		else if(fact == "INDFOR") return 2;
		else if(fact == "CIV") return 3;
		return -1;
	}
	
	int GetCharacterSlots(IEntity Character, out notnull array<LoadoutAreaType> CharacterSlots)
	{
    IEntitySource Source = SCR_BaseContainerTools.FindEntitySource(Resource.Load(Character.GetPrefabData().GetPrefabName()));
    IEntityComponentSource inventoryManagerComponent = SCR_BaseContainerTools.FindComponentSource(Source, BaseLoadoutManagerComponent);
    if (!inventoryManagerComponent)
        return 0;
    
    BaseContainerList slotList = inventoryManagerComponent.GetObjectArray("Slots");
    if (!slotList)
        return 0;
    
    for (int i, count = slotList.Count(); i < count; i++)
    {
        BaseContainer slot = slotList.Get(i);
        LoadoutAreaType slotArea;    
        slot.Get("AreaType", slotArea);
        CharacterSlots.Insert(slotArea);
    }
    return CharacterSlots.Count();
	}
	
}



/*
{
	static void SetPlayerWeapon(IEntity player, int playerId)
    {
		// Find/Create required entities and components
        ArmaReforgerScripted game = GetGame();
        GunGameMode gameMode = GunGameMode.gunGameMode;
		GunGameWeaponSelection weaponSelection = gameMode.getWeaponForPlayer(playerId);
        IEntity weapon = game.SpawnEntityPrefab(Resource.Load(weaponSelection.getResourceName()), null, null);
		SCR_CharacterControllerComponent characterController = SCR_CharacterControllerComponent.Cast(player.FindComponent(SCR_CharacterControllerComponent));
		InventoryStorageManagerComponent inventoryStorageManager = characterController.GetInventoryStorageManager();
		
		// Clear out all equipped weapons
		array<Managed> cwscs = new array<Managed>();
		player.FindComponents(CharacterWeaponSlotComponent, cwscs);
		foreach(Managed cwscManaged : cwscs)
		{
			CharacterWeaponSlotComponent cwsc = CharacterWeaponSlotComponent.Cast(cwscManaged);
			BaseInventoryStorageComponent inventory = cwsc.GetSlotInfo().GetStorage();
			array<IEntity > entities = new array<IEntity >();
			inventory.GetAll(entities);
			foreach(IEntity entity : entities)
			{
				inventoryStorageManager.TryRemoveItemFromStorage(entity, inventory);
			}
		}
		// Why does this need to be a delayed call! 250ms seems to work every time, but 0 or 1 doesn't.
		GetGame().GetCallqueue().CallLater(setPlayerWeapon2, 250, false, player, weapon, weaponSelection);
    }
	
	static void setPlayerWeapon2(IEntity player, IEntity weapon, GunGameWeaponSelection weaponSelection)
	{
		// Get components back
		SCR_CharacterControllerComponent characterController = SCR_CharacterControllerComponent.Cast(player.FindComponent(SCR_CharacterControllerComponent));
		InventoryStorageManagerComponent inventoryStorageManager = characterController.GetInventoryStorageManager();
		inventoryStorageManager.TryInsertItemInStorage(weapon, inventoryStorageManager.FindStorageForItem(weapon, EStoragePurpose.PURPOSE_WEAPON_PROXY));
		// Send an RPC to the client to equip the new weapon
		WeaponEquipComponent wec = WeaponEquipComponent.Cast(player.FindComponent(WeaponEquipComponent));
		GetGame().GetCallqueue().CallLater(wec.setWeapon, 0, false, player, weapon);
	}

}
*/