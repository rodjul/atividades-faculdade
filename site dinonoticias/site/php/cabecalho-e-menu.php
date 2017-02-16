<?
include "banco_conexao.php";

?>

<!DOCTYPE html>
<html>
	<head>
		<title><?php print $cabecalho_title; ?></title>
		<meta charset='utf-8' />
        <link rel="stylesheet" href="css/style.css" />
        <?php print @$cabecalho_css; ?>
	</head>
	<body>
		<header>
            <figure>
                <img alt="logo" src="img/logo.jpg"  id="logo" />
            </figure>
			<form class="form1 fixpesq">
                <label for="pesquisa">Pesquisar:</label><input type="search" id="pesquisa" name="pesquisa" value="" placeholder="Pesquise aqui" />
                
                <!--<input type="submit" value="" class="iconepesquisa">-->
			</form>
			<form class="form2 fixmenu" action="login.php" method="post">
                <label for="login">Login:</label><br>
                <input type="text" name="login" id="login" value="" placeholder="Login" /><br>
                <label for="senha">Senha:</label><br>
                <input type="password" name="senha" id="senha" value="" placeholder="Senha" /><br>
                <input type="submit" value="Logar" />
            </form>   
		</header>
		<nav>
			<ul class="nav fixnav">
				<li class="vermelho"><a href="index.html">Home</a></li>
				<li class="amarelo"><a href="atualidades.php">Atualidades</a></li>
				<li class="laranja"><a href="economia.php">Economia</a></li>
				<li class="verde"><a href="esportes.php">Esportes</a></li>
				<li class="roxo"><a href="celebridades.php">Celebridades</a></li>
				<li class="azul"><a href="noticiasmundo.php">Notícias do mundo</a></li>
				<li class="vermelho"><a href="cadastrase.php">Cadastre-se</a></li>
			</ul>
		</nav>
        
        