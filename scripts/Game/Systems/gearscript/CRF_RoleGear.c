[BaseContainerProps(configRoot: true), BaseContainerCustomTitleField("RoleSpecificGear")]
class CRF_RoleGear
{
	[Attribute(category: "settings")]
	bool m_isLeader;
	[Attribute(defvalue: "true", category: "settings")]
	bool m_useWeaponSettings;
	[Attribute(defvalue: "true", category: "settings")]
	bool m_useMedicalSeetings;
	[Attribute(defvalue: "true", category: "settingqs")]
	bool m_useLoadoutSettings;
	[Attribute(category: "settings")]
	bool m_hasBinos;
	[Attribute(category: "Weapon")]
	ResourceName m_Weapon;
	[Attribute(category: "Weapon")]
	ResourceName m_Primary2;
	[Attribute(category: "Weapon")]
	ResourceName m_Sidearm;
	[Attribute(category: "AMMO")]
	ref array<ref ResourceName> m_Ammo;
	[Attribute(category: "Extra")]
	array<ref ResourceName> m_MiscItems;
	[Attribute(category: "Loadout")]
	array<ref ResourceName> m_Helmet;
	[Attribute(category: "Loadout")]
	array<ref ResourceName> m_Jacket;
	[Attribute(category: "Loadout")]
	array<ref ResourceName> m_ArmoredVest;
	[Attribute(category: "Loadout")]
	array<ref ResourceName> m_Pants;
	[Attribute(category: "Loadout")]
	array<ref ResourceName> m_Boots;
	[Attribute(category: "Loadout")]
	array<ref ResourceName> m_Backpack;
	[Attribute(category: "Loadout")]
	array<ref ResourceName> m_Vest;
	[Attribute(category: "Loadout")]
	array<ref ResourceName> m_Handwear;
	[Attribute(category: "Loadout")]
	array<ref ResourceName> m_Head;
	[Attribute(category: "Loadout")]
	array<ref ResourceName> m_Eyes;
	[Attribute(category: "Loadout")]
	array<ref ResourceName> m_Ears;
	[Attribute(category: "Loadout")]
	array<ref ResourceName> m_Face;
	[Attribute(category: "Loadout")]
	array<ref ResourceName> m_Neck;
	[Attribute(category: "Loadout")]
	array<ref ResourceName> m_Extra;
	[Attribute(category: "Loadout")]
	array<ref ResourceName> m_Extra2;
	[Attribute(category: "Loadout")]
	array<ref ResourceName> m_Waist;
	[Attribute(category: "Loadout")]
	array<ref ResourceName> m_Extra3;
	[Attribute(category: "Loadout")]
	array<ref ResourceName> m_Extra4;
}
