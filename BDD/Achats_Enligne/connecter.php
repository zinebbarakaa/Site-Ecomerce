<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Page de connexion moderne</title>
	<link rel="stylesheet" type="text/css" href="style1.css">
	<link rel="stylesheet" href="https://pro.fontawesome.com/releases/v5.10.0/css/all.css" integrity="sha384-AYmEC3Yw5cVb3ZcuHtOA93w35dYTsvhLPVnYs9eStHfGJvOvKxVfELGroGkvsg+p" crossorigin="anonymous"/>
	<style type="text/css">
		.inscription a {
			text-decoration: none;
			color: #eb7371;
		}
	</style>
	
</head>
<body >
		<form action="login.php" method="POST">
			<h1>Se Connecter</h1>
			<?php 
			 if(isset($_GET['erreur'])) {?>
			 	<p class="erreur" style="
			 	background-color: #F2D7D5 ;
				color: #A94442;
				padding: 10px;
				width: 95%;
				border-radius: 5px;
				"><?php echo $_GET['erreur']; ?></p>
			<?php }?>
			<div class="social-media">
					<p><i class="fab fa-google"></i></p>
					<p><i class="fab fa-youtube"></i></p>
					<p><i class="fab fa-facebook"></i></p>
					<p><i class="fab fa-instagram"></i></p>
			</div>
				<p class="chose-email">Connecter avec votre adresse email:</p>

				<div class="inputs">
					<input type="email" name="email" placeholder="Email" >
					<input type="password" name="pass" placeholder="Mot de passe" >
				</div>
				<p class="inscription" style="color: black;">je n'ai pas d'un <a href="inscreption.php" style="color:#eb7371;">compte</a>. Je m'en <span>crée</span>  un.</p>
				
				<div align="center">
					 <button type="submit" name="submit" style="background-color: #eb7371;">Se connecter</button>
				</div>
		</form >
	</body>
</html>