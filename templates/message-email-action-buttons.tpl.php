<?php if ($can_send || $can_create_reply || $can_clone): ?>
<div class="bonsai-message-email-section bonsai-message-email-actions">

  <?php /* Send button */ ?>
  <?php if ($can_send): ?>
  <form method="POST" action="<?php print url('bonsai/messages/' . $node->nid . '/send'); ?>">
    <button type="submit" class="btn btn-link" role="button">
      <span class="fa fa-send"></span> Send
    </button>
  </form>
  <?php endif; ?>

  <?php /* Reply buttons */ ?>
  <?php if ($can_create_reply && ($reply_link || $reply_all_link)): ?>
    <div class="btn-group">
      <button type="button" class="btn btn-link dropdown-toggle" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
        <span class="fa fa-reply"></span> Reply <span class="caret"></span>
      </button>
      <ul class="dropdown-menu">
        <li><?php print $reply_link; ?></li>
        <li><?php print $reply_all_link; ?></li>
      </ul>
    </div>
  <?php endif; ?>

  <?php /* Move buttons */ ?>
  <?php if ($can_move && $move_buttons): ?>
    <div class="btn-group">
      <button type="button" class="btn btn-link dropdown-toggle" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
        <span class="fa fa-arrows-alt"></span> Move <span class="caret"></span>
      </button>
      <ul class="dropdown-menu">
        <?php foreach($move_buttons as $move_button): ?>
          <li>
            <form method="POST" action="<?php print url('bonsai/messages/' . $node->nid . '/move'); ?>">
              <input type="hidden" name="tid" value="<?php print $move_button['tid']; ?>">
              <button type="submit" class="btn btn-link" role="button">
                <span class="fa fa-<?php print $move_button['icon']; ?>"></span> <?php print $move_button['name']; ?>
              </button>
            </form>
          </li>
        <?php endforeach; ?>
      </ul>
    </div>
  <?php endif; ?>

  <?php /* Clone button */ ?>
  <?php if ($can_clone): ?>
    <form method="POST" action="<?php print url('bonsai/messages/' . $node->nid . '/clone'); ?>">
      <button type="submit" class="btn btn-info btn-link" role="button">
        <span class="fa fa-copy"></span> Clone
      </button>
    </form>
  <?php endif; ?>
</div>
<?php endif; ?>
