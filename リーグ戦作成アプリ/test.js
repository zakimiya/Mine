function check(){

	var flag = 0;

	if(document.form1.team_no.value == "" || 
           document.form1.coat_no.value == "" || 
           document.form1.game_no.value == "")
		flag = 1;

	// İ’èI—¹


	if(flag){

		window.alert('•K{€–Ú‚É–¢“ü—Í‚ª‚ ‚è‚Ü‚µ‚½'); // “ü—Í˜R‚ê‚ª‚ ‚ê‚ÎŒxƒ_ƒCƒAƒƒO‚ğ•\¦
		return false; // ‘—M‚ğ’†~

	}
	else{

		return true; // ‘—M‚ğÀs

	}

}

function out(a,b,c){

	document.write(a);
	document.write("! ");
	document.write(b);
	document.write("! ");
	document.write(c);
	document.write("! ");

}


function out_of_input(){
	team_no = parseInt(document.form1.team_no.value);
	coat_no = parseInt(document.form1.coat_no.value);
	game_no = parseInt(document.form1.game_no.value);

	team_name = ["‡@","‡A","‡B","‡C","‡D","‡E","‡F","‡G","‡H","‡I","‡J","‡K","‡L","‡M","‡N","‡O","‡P","‡Q","‡R","‡S"];
	var go_count = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
	var go_flag = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];

	var combi_count = [
	[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
	];
	var ok_flag_team = 0;
	var ok_flag_combi = 0;
	var game_count = 0;

	for(i=0;i<20;i++){
		if(i<team_no) go_count[i] = 0;
		else go_count[i] = 1000;
	}

	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
		    if (i<team_no && j<team_no) combi_count[i][j] = 0;
		    else combi_count[i][j] = 1000;
		}
	}

	for(i=0;i<game_no;i++){

		go_flag = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];

		
		for(j=0;j<coat_no;j++){
			ok_flag_team = 0;
			ok_flag_combi = 0;

				if(game_count==(team_no * (team_no-1))/2){
					for(k=0;k<20;k++){
						for(l=0;l<20;l++){
						    if (k<team_no && l<team_no) combi_count[k][l] = 0;
						    else combi_count[k][l] = 1000;
						}
					}
					game_count = 0;
				}

			while(ok_flag_combi<1){

				if(game_count==(team_no * (team_no-1))/2){
					for(k=0;k<20;k++){
						for(l=0;l<20;l++){
						    if (k<team_no && l<team_no) combi_count[k][l] = 0;
						    else combi_count[k][l] = 1000;
						}
					}
					game_count = 0;
				}

				while(ok_flag_team<1){
					rnd_a = Math.floor( Math.random() * team_no );
					if(go_flag[rnd_a]==0 && go_count[rnd_a]==Math.min.apply(null, go_count)){
					  	go_flag[rnd_a] = 1;
					 	go_count[rnd_a] = go_count[rnd_a] + 1;
						ok_flag_team = 1;
					}
				}
				
				ok_flag_team = 0;

				while(ok_flag_team<1){
					rnd_b = Math.floor( Math.random() * team_no );
					if(go_flag[rnd_b]==0 && go_count[rnd_b]==Math.min.apply(null, go_count)){
					  	go_flag[rnd_b] = 1;
					 	go_count[rnd_b] = go_count[rnd_b] + 1;
						ok_flag_team = 1;
					}
				}

				
				if(combi_count[rnd_a][rnd_b]==0 && combi_count[rnd_b][rnd_a]==0){
					document.write("| ");
					document.write(team_name[rnd_a]);
					document.write(" vs ");
					document.write(team_name[rnd_b]);
					document.write(" |");
					combi_count[rnd_a][rnd_b] = combi_count[rnd_a][rnd_b] + 1;
					combi_count[rnd_b][rnd_a] = combi_count[rnd_b][rnd_a] + 1;
					game_count = game_count + 1;
					ok_flag_combi = 1;
				}
			}
		}
		document.write("<br><br>");
	}

/*
	for(i=0;i<game_no;i++){
		for(j=0;j<coat_no;j++){
			rnd = Math.floor( Math.random() * team_no );
			document.write(team_name[rnd]);
			document.write(" vs ");
			rnd = Math.floor( Math.random() * team_no );
			document.write(team_name[rnd]);
		}
		document.write("<br><br>");
	}
*/
	document.write("<br>‚â‚è’¼‚·‚É‚Íƒy[ƒW‚ğXV‚µ‚Ä‚­‚¾‚³‚¢");
}
