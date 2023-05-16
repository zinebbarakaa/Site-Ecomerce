<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Créer un compte</title>
	<link rel="stylesheet" href="https://pro.fontawesome.com/releases/v5.10.0/css/all.css" integrity="sha384-AYmEC3Yw5cVb3ZcuHtOA93w35dYTsvhLPVnYs9eStHfGJvOvKxVfELGroGkvsg+p" crossorigin="anonymous"/>
	<script type="text/javascript">
		
	</script>
	<style type="text/css">
		body {
	display: flex;
	justify-content: center;
	align-items: center;
	background-color: #f5f5f5;
	

}
body form {
	margin-top: 20px;
	background-color: #fff;
	padding: 40px 60px;
	border-radius: 15px;
	min-width: 300px;
}
form h1{
	color: #eb7371;
	text-align: center;
}
form .inputs label{
	font-size: 15px;
	
}
form .inputs{
	display: flex;
	flex-direction: column;

}
form .inputs label,input {
	margin-bottom: 10px;
}

form .inputs input{
	padding: 10px;
	border-radius: 5px;
	border: none;
	background-color: #f2f2f2;
	margin-bottom: 10px;
	outline: none;
}
form button{
	margin-top: 10px;
	padding: 15px 25px;
	font-size: 15px;
	border: none;
	border-radius: 5px;
	background-color: #eb7371;
	color: #fff;
	outline: none;
	cursor: pointer;
}
form .inputs table tr td i,label{
	color: black;
}
form a {
	margin-top: 15px;
	text-align: center;
	color: #eb7371;
	font-size: 15px;
}
	</style>
	
</head>
<body>
	<form  action="valider_inscreption.php" method="POST">
		<h1>Créer un Compte</h1>
	<div class="inputs">
		<table>
			<tr>
				<td width="20px">
					<i class="fas fa-user"></i>
				</td>
				<td>
					<label>Votre Nom:</label>
				</td>
			</tr>
		</table>
		<input type="text" name="nom" placeholder="Entrer votre nom" id="nom">
		<table>
			<tr>
				<td width="20px">
					<i class="fas fa-user"></i>
				</td>
				<td>
					<label>Votre Prénom:</label>
				</td>
			</tr>
		</table>
		<input type="text" name="prenom" placeholder="Entrer votre prenom" id="prenom">	
		<table>
			<tr>
				<td width="20px">
					<i class="fas fa-envelope-open"></i>
				</td>
				<td>
					<label>Votre Email:</label>	
				</td>
			</tr>
		</table>
		<input type="email" name="email" id="email" placeholder="Entrer votre email">
		<table>
			<tr>
				<td width="20px">
					<i class="fas fa-calendar-week"></i>
				</td>
				<td>
					<label>Date de Naissance:</label>	
				</td>
			</tr>
		</table>
		<input type="Date" name="date_naiss" id="date_naiss">
		<table>
			<tr>
				<td width="20px">
					<i class="fas fa-phone"></i>
				</td>
				<td>
					<label>Votre Numéro de Téléphone</label>	
				</td>
			</tr>
		</table>
		<input type="tel" name="tele" placeholder="+212" id="tele">
		<table>
			<tr>
				<td width="20px">
					<i class="fas fa-home"></i>
				</td>
				<td>
					<label>Votre Adresse</label>	
				</td>
			</tr>
		</table>
		<input type="textarea" name="adresse" id="adresse" placeholder="Entrer votre adresse">
		<table>
			<tr>
				<td width="20px">
					<i class="fas fa-lock"></i>
				</td>
				<td>
					<label>Votre Mot de Passe:</label>
	
				</td>
			</tr>
		</table>
		<input type="password" name="pass" id="pass">
		<table>
			<tr>
				<td width="20px">
					<i class="fas fa-unlock"></i>
				</td>
				<td>
					<label>Confirmer Votre Mot de Passe:</label>
	
				</td>
			</tr>
		</table>
		<input type="password" name="passc" id="passc">
		<button type="submit" name="submit">Créer Compte</button>
		<a href="connecter.php">J'ai déja un Compte</a>
	</div>
		
	</form>
</body>
</html>