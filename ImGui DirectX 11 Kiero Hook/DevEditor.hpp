

void Trickshot_Cam_Tab()
{
	Var::X = *(float*)Offset::POS_X;
	Var::Y = *(float*)Offset::POS_Y;
	Var::Z = *(float*)Offset::POS_Z;

	if (TAB_boutton == 4)
	{
		ImGui::SetCursorPos(ImVec2(246, 45));
		ImGui::BeginChild("Camo TAB", ImVec2(640, 735));
		ImGui::Dummy(ImVec2(0.0f, 5.0f));

		if (ImGui::CollapsingHeader("Position"))
		{
		
		    char resultat[256];
			sprintf(resultat, "Position X = %0.0f, Y = %0.0f, Z = %0.0f", Var::X, Var::Y, Var::Z);
			ImGui::Text(resultat);


		}

		ImGui::EndChild();
	}
}